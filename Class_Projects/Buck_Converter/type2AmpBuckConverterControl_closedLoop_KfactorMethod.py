# -*- coding: utf-8 -*-
"""
Created on Sun Mar 15 23:49:51 2026

@author: jg
"""

import numpy as np
#import matplotlib.pyplot as plt
import control as ct


# Plant parameters
Vin, Vramp, L, C, Resr, Rload = 6.0, 1.5, 100e-6, 75e-6, 0.4, 2.0

# Define Plant transfer function Gp(s)
num_p = [Vin/Vramp * Resr * C, Vin/Vramp]
den_p = [L * C, (L/Rload + Resr * C), 1.0]
#Gp = signal.TransferFunction(num_p, den_p)
Gp = ct.tf(num_p,den_p)
fsw = 50e3



# 3. Type 2 Compensator Design (K-Factor Method)
fc = fsw / 10       # Target crossover frequency
wc = 2 * np.pi * fc

# Get plant gain and phase at fc
mag_p, phase_p, _ = ct.freqresp(Gp, [wc])
phase_p_deg = np.degrees(phase_p[0])

# Calculate phase boost for a target 60 deg Phase Margin
PM_target = 60
boost = PM_target - (180 + phase_p_deg) + 90
K = np.tan(np.radians(boost / 2 + 45))

wz = wc / K         # Compensator Zero
wp = wc * K         # Compensator Pole

# Form the compensator: Gc(s) = Kc * (s + wz) / (s * (s + wp))
C_norm = ct.TransferFunction([1, wz], [1, wp, 0])
mag_c_norm, _, _ = ct.freqresp(C_norm, [wc])
Kc = 1 / (mag_p[0] * mag_c_norm[0])
Gc = Kc * C_norm

loopGain = ct.series(Gp, Gc)

mag, phase, w = ct.bode(loopGain, plot=True, margins=True)
