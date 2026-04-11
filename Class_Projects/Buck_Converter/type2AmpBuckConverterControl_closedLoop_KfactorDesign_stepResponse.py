# -*- coding: utf-8 -*-
"""
Created on Fri Mar 20 23:42:21 2026

@author: jg
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# 1. System Parameters
# Vin, Vref, L, C, Resr = 12.0, 5.0, 10e-6, 100e-6, 0.02
# R_init, R_final = 2.5, 5.0
# fs, Vramp = 200e3, 1.0
# fc, PM_target = fs / 10, 60  # Design at 20kHz
# w_c = 2 * np.pi * fc

Vin, Vref, L, C, Resr = 6.0, 3.3, 100e-6, 100e-6, 0.5
R_init, R_final = 2.0, 4.0
fs, Vramp = 100e3, 1.0
fc, PM_target = fs / 10, 60
w_c = 2 * np.pi * fc
# 2. Plant Gp(s) at R_init
num_p = [(Vin/Vramp)*Resr*C, (Vin/Vramp)]
den_p = [L*C, (L/R_init + Resr*C), 1]
sys_p = signal.TransferFunction(num_p, den_p)
_, mag_p_db, phase_p = signal.bode(sys_p, w=[w_c])
mag_p_fc, phase_p_fc = 10**(mag_p_db[0]/20), phase_p[0]

# 3. K-Factor Design (Type 2)
boost = PM_target - 90 - phase_p_fc
k = np.tan(np.radians(boost/2 + 45))
fz, fp = fc/k, fc*k
wz, wp = 2*np.pi*fz, 2*np.pi*fp

# Gc(s) calculation
num_shape = [1/wz, 1]
den_shape = [1/wp, 1, 0]
_, mag_s_db, _ = signal.bode(signal.TransferFunction(num_shape, den_shape), w=[w_c])
gc0 = 1 / (mag_p_fc * 10**(mag_s_db[0]/20))
num_c, den_c = [gc0/wz, gc0], [1/wp, 1, 0]

# 4. Stability Analysis
sys_loop = signal.TransferFunction(np.polymul(num_p, num_c), np.polymul(den_p, den_c))
w_vec = np.logspace(2, 6, 1000)
w_b, m_b, p_b = signal.bode(sys_loop, w=w_vec)
idx_fc = np.argmin(np.abs(m_b))
act_fc = w_b[idx_fc]/(2*np.pi)
act_pm = 180 + p_b[idx_fc]

# 5. Time Domain Simulation (Step @ 400us)
t = np.linspace(0, 0.0012, 6000)
t_step = 400e-6
I_init, I_final = Vref/R_init, Vref/R_final
dI = I_final - I_init # -1.0A

# Sensitivity: Vout/Iload and IL/Iload
den_cl = np.polyadd(np.polymul(den_p, den_c), np.polymul(num_p, num_c))
sys_zcl = signal.TransferFunction(np.polymul([L*Resr*C, L, 0], den_c), den_cl)
sys_til = signal.TransferFunction(np.polymul(den_p, den_c), den_cl)

t_post = t[t >= t_step] - t_step
_, v_dev = signal.step(sys_zcl, T=t_post)
_, i_dev = signal.step(sys_til, T=t_post)

vout = np.full_like(t, Vref)
vout[t >= t_step] = Vref - (v_dev * dI)
il = np.full_like(t, I_init)
il[t >= t_step] = I_init + (i_dev * dI)

# 6. Plotting
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(8, 12))
ax1.plot(t*1e6, vout, 'b'); ax1.axvline(400, color='k', ls='--')
ax1.set_ylabel('Vout (V)'); ax1.set_title('Step Response at 400µs'); ax1.grid(True)

ax2.plot(t*1e6, il, 'orange'); ax2.axvline(400, color='k', ls='--')
ax2.set_ylabel('IL (A)'); ax2.set_xlabel('Time (µs)'); ax2.grid(True)

ax3.semilogx(w_b/(2*np.pi), m_b, 'g', label='Mag')
ax3_ph = ax3.twinx()
ax3_ph.semilogx(w_b/(2*np.pi), p_b, 'r', label='Phase')
ax3.set_ylabel('Gain (dB)'); ax3_ph.set_ylabel('Phase (deg)')
ax3.set_title(f'Bode Analysis: PM={act_pm:.1f}° @ {act_fc/1e3:.1f}kHz'); ax3.grid(True, which='both')
plt.tight_layout(); plt.show()
