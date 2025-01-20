import numpy as np
import matplotlib.pyplot as plt


Fs = 5000  
n = np.arange(0, 100)  # Discrete time indices from 0 to 99
F0_values = [500, 2000, 3000, 4500]  

# A part
# sampled signals for values of F0_values
plt.figure(figsize=(12, 8))
for i, F0 in enumerate(F0_values):
    x_n = 5 * np.sin(2 * np.pi * (F0 / Fs) * n)  # Compute x(n)
    plt.subplot(2, 2, i + 1)
    plt.stem(n, x_n, use_line_collection=True)
    
    plt.title(f"x(n) for F0={F0} Hz")
    plt.xlabel("n")
    plt.ylabel("Amplitude")
    plt.grid(True)

plt.tight_layout()
plt.show()

# B part
F0 = 2000  # Signal frequency in Hz
Fs = 50000  # Sampling frequency in Hz
x_n = 5 * np.sin(2 * np.pi * (F0 / Fs) * n)  # Compute x(n)

# Plot x(n)
plt.figure(figsize=(10, 5))
plt.stem(n, x_n, use_line_collection=True)
plt.title("x(n) for F0=2000 Hz and Fs=50 kHz")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()

# Create y(n) by taking even-numbered samples of x(n)
y_n = x_n[::2]  # Every second sample
n_even = n[::2]  # Corresponding indices

# Plot y(n)
plt.figure(figsize=(10, 5))
plt.stem(n_even, y_n, use_line_collection=True)
plt.title("y(n) (Even-numbered samples of x(n))")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid(True)
plt.show()