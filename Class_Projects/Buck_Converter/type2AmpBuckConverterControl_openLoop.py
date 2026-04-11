# -*- coding: utf-8 -*-
"""
Created on Sun Mar 15 20:46:07 2026

@author: jg
"""

import numpy as np
#from scipy import signal
import matplotlib.pyplot as plt
import control as ct
from control import tf, step_response, impulse_response, bode, pole, zero, pzmap

# Plant parameters
Vin, Vramp, L, C, Resr, Rload = 6.0, 1.5, 100e-6, 75e-6, 0.4, 2.0

# Define Plant Gp(s)
num_p = [Vin/Vramp * Resr * C, Vin/Vramp]
den_p = [L * C, (L/Rload + Resr * C), 1.0]
#Gp = signal.TransferFunction(num_p, den_p)
Gp = ct.tf(num_p,den_p)

# Define Type 2 Compensator Gc(s)
R1, R2, C1, C2 = 1e3, 2.54e3, 48.2e-9, 1.66e-9
#wz, wp, K = 2*np.pi*2500, 2*np.pi*50000, 5000
wz, wp, K = 1/(R2*C1), (C1+C2)/(R2*C1*C2), 1/(R1*C2)
#wz, wp, K = 1/(R2*C1), 1/(R2*C2), 1/(R1*C2)
num_c = [K, K * wz]
den_c = [1.0, wp, 0.0]
#Gc = signal.TransferFunction(num_c, den_c)
Gc = ct.tf(num_c,den_c)
G_total = ct.series(Gp, Gc)
"""
# Define 's' variable
s = ct.TransferFunction.s

# Define transfer functions using algebra
G1 = 1 / (s + 1)
G2 = 2 / (s + 2)

# Multiply
G_total_s = G1 * G2

print(G_total_s)

"""
plt.close('all')
# Bode Plot for Open Loop Gain (Gc * Gp)
#w, mag, phase = signal.bode(signal.Series(Gc, Gp))
mag, phase, w = ct.bode(G_total, plot=True, margins=True)
#w, mag, phase = signal.bode(G_total)
#plt.semilogx(w/(2*np.pi), mag)
# plt.title("Open Loop Gain (Type 2)")
# plt.show()
# Calculate the gain and phase margins
# gm: gain margin (a factor, not dB)
# pm: phase margin (in degrees)
# wcg: gain crossover frequency (where phase is -180 deg)
# wcp: phase crossover frequency (where gain is 1 or 0 dB)
gm, pm, wcg, wcp = ct.margin(G_total)

# Print the results
print(f"Gain margin (factor): {gm}")
print(f"Gain margin (dB): {20 * np.log10(gm)}") # Often expressed in dB
print(f"Phase margin (deg): {pm}")
print(f"Gain crossover frequency (Hz): {wcp/(2*np.pi)}")
print(f"Phase crossover frequency (Hz): {wcg/(2*np.pi)}")

# Optional: Plot the Bode plot with margins indicated
# plt.figure()
# ct.bode_plot(G_total, margins=True, wrap_phase=True)
# plt.show()
# ct.bode_plot()
 
