
#1.
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency =2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
sine_wave = amplitude * np.sin(2*np.pi*frequency * t)
plt.figure(figsize=(10,4))
plt.plot(t, sine_wave)
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.title("Sine Wave")
plt.grid(True)
plt.show()
# 2
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency=2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
square_wave = amplitude * np.sign(np.sin(2*np.pi*frequency*t))
plt.figure(figsize=(10,4))
plt.plot(t, square_wave)
plt.xlabel("Time(s)")
plt.ylabel("Amplitude(V)")
plt.title("Square Wave")
plt.grid(True)
plt.show()
# 3
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency =2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
triangle_wave = amplitude *(2 * np.abs(np.mod(t*frequency,1)-0.5)-0.5)
plt.figure(figsize=(10,4))
plt.plot(t, triangle_wave)
plt.xlabel("Time(s)")
plt.ylabel("Amplitude(V)")
plt.title("Triangle Wave")
plt.grid(True)
plt.show()
# 4
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency =2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
sine_wave30 = amplitude * np.sin(2*np.pi*frequency * t+np.pi/6)
#print(t)
#print(sine_wave)
plt.subplot(2,2,1)

plt.plot(t, sine_wave30)
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.title("Sine Wave & Phase Difference: 30")
plt.grid(True)
plt.show()
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency = 2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
sine_wave45 = amplitude * np.sin(2*np.pi*frequency * t+np.pi/4)
plt.subplot(2,2,2)

plt.plot(t, sine_wave45)
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.title("Sine Wave & Phase difference: 45")
plt.grid(True)
plt.show()
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency = 2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
sine_wave60 = amplitude * np.sin(2*np.pi*frequency * t+np.pi/3)
plt.subplot(2,2,3)

plt.plot(t, sine_wave60)
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.title("Sine Wave & Phase Difference: 60")
plt.grid(True)
plt.show()
import numpy as np
import matplotlib.pyplot as plt
amplitude = 5
frequency = 2
sampling_rate=100
duration=1
t=np.arange(0,duration,1/sampling_rate)
sine_wave90 = amplitude * np.sin(2*np.pi*frequency * t+np.pi/2)
plt.subplot(2,2,4)

plt.plot(t, sine_wave90)
plt.xlabel("Time")
plt.ylabel("Amplitude")
plt.title("Sine Wave & Phase Difference:90")
plt.grid(True)
plt.show()

