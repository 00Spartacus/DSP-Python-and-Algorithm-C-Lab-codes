import numpy as np
import matplotlib.pyplot as plt

# Square Wave Parameters
A = 2
f = 2 
sampling_rate = 100  
duration = 1  
t = np.arange(0, duration, 1/sampling_rate)

# Original Square Wave
signal = A*np.sign(np.sin(2*np.pi*f*t)) # square wave

# Transformations
# 1. Delay by 0.2 seconds
t_delay = t - 0.2

# 2. Advance by 0.2 seconds
t_advance = t + 0.2

# 3. Reflect vertically
signal_reflect = -signal

# 4. Stretch by factor of 2
t_stretch = np.linspace(0, 2 * duration, int(sampling_rate * duration), endpoint=False)
signal_stretch = A * np.sign(np.sin(2 * np.pi * (f / 2) * t_stretch))

# 5. Compress by factor of 2
t_compress = np.linspace(0, duration / 2, int(sampling_rate * duration), endpoint=False)
signal_compress = A * np.sign(np.sin(2 * np.pi * (2 * f) * t_compress))

# Plotting
plt.figure(figsize=(12, 10))

plt.subplot(3, 2, 1)
plt.plot(t, signal)
plt.title('Original Signal')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(3, 2, 2)
plt.plot(t_delay, signal)
plt.title('Delayed (0.2s)')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(3, 2, 3)
plt.plot(t_advance, signal)
plt.title('Advanced (0.2s)')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(3, 2, 4)
plt.plot(t, signal_reflect)
plt.title('Reflected Vertically')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(3, 2, 5)
plt.plot(t_stretch, signal_stretch)
plt.title('Stretched (2x Period)')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(3, 2, 6)
plt.plot(t_compress, signal_compress)
plt.title('Compressed (0.5x Period)')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.grid()

plt.tight_layout()
plt.show()


