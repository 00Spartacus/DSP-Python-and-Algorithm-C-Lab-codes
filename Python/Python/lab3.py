# 1
import numpy as np
import matplotlib.pyplot as plt
signal=[-1,2,-4,5,6,4,5,5,7,8,-4,-6,-5,-4,-3,-2]#16 sample
origin=5
time=np.arange(-origin,len(signal)-origin)#-5-(16-5)#start,ending
plt.figure(figsize=(8,10))
plt.subplot(3,2,1)
plt.stem(time, signal,'r+')
plt.title('Original Signal')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')


delay=4
time_delay= np.arange(-origin+delay,len(signal)-origin+delay)
plt.subplot(3,2,2)
plt.stem(time_delay, signal,'b*')
plt.title('Delayed Signal(x[n-4])')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')

advance=4
time_advance=np.arange(-origin-advance,len(signal)-origin-advance)
plt.subplot(3,2,3)
plt.stem(time_advance,signal,'g*')
plt.title('Advance signal(x[n+4])')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')

reflected_time=-time
plt.subplot(3,2,4)
plt.stem(reflected_time,signal,'r*')
plt.title('Reflected Signal(x[-n])')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')

scale=4
time_scale=np.linspace(-origin*scale,(len(signal)-origin)*scale,len(signal))
#linespace (starting, ending ,sample) range=-20 to 44
plt.subplot(3,2,5)
plt.stem(time_scale,signal,'g*')
plt.title('Scaled Signal streched')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')

scale=0.5
time_scale=np.linspace(-origin*scale,(len(signal)-origin)*scale,len(signal))
plt.subplot(3,2,6)
plt.stem(time_scale,signal,'g*')
plt.title('Scaled Signal compressed')
plt.xlabel('Time(s)')
plt.ylabel('Amplitude')
plt.tight_layout()
plt.show()
# import numpy as np
# import matplotlib.pyplot as plt

# signal = [-1, 2, -4, 5, 6, 4, 5, 5, 7, 8, -4, -6, -5, -4, -3, -2]
# origin = 5
# time = np.arange(-origin, len(signal) - origin)
# print(time)

# plt.figure(figsize=(12, 12))

# plt.subplot(3, 2, 1)
# plt.stem(time, signal, 'r+')
# plt.title('Original Signal')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')

# delay = 4
# time_delay = np.arange(-origin + delay, len(signal) - origin + delay)
# plt.subplot(3, 2, 2)
# plt.stem(time_delay, signal, 'b*')
# plt.title('Delayed Signal(x[n-4])')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')

# advance = 4
# time_advance = np.arange(-origin - advance, len(signal) - origin - advance)
# print(time_advance)
# plt.subplot(3, 2, 3)
# plt.stem(time_advance, signal, 'g*')
# plt.title('Advance signal(x[n+4])')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')

# reflected_time = -time
# plt.subplot(3, 2, 4)
# plt.stem(reflected_time, signal, 'r*')
# plt.title('Reflected Signal(x[-n])')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')

# scale = 4
# time_scale = np.linspace(-origin * scale, (len(signal) - origin) * scale, len(signal))
# plt.subplot(3, 2, 5)
# plt.stem(time_scale, signal, 'g*')
# plt.title('Scaled Signal stretched')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')

# scale = 0.5
# time_scale = np.linspace(-origin * scale, (len(signal) - origin) * scale, len(signal))
# plt.subplot(3, 2, 6)
# plt.stem(time_scale, signal, 'g*')
# plt.title('Scaled Signal compressed')
# plt.xlabel('Time(s)')
# plt.ylabel('Amplitude')
# plt.tight_layout()
# plt.show()
# import numpy as np
# import matplotlib.pyplot as plt


# signal = []
# for i in range(-22,23):
#   signal.append(i)

# plt.figure(figsize=(12, 12))

# origin = 22
# time = np.arange(-origin, len(signal) - origin)

# plt.subplot(3, 2, 1)
# plt.stem(time, signal, 'r+')
# plt.title('Original Signal')
# plt.xlabel('Time (s)')
# plt.ylabel('Amplitude')

# cnt=2

# delay_advance=[2,-(2+2)]
# for i in range(2):
#     change=delay_advance[i]
#     time_delay = np.arange(-origin + change, len(signal) - origin + change)
#     plt.subplot(3, 2, cnt)
#     plt.stem(time_delay, signal, 'b+')
#     if i==0:
#       plt.title('Delayed Signal')
#     else:
#       plt.title('Advance Signal')
#     plt.xlabel('Time')
#     plt.ylabel('Amplitude')
#     cnt+=1


# reflected_time = -time
# plt.subplot(3, 2, cnt)
# plt.stem(reflected_time, signal, 'm+')
# plt.title('Reflected Signal')
# plt.xlabel('Time')
# plt.ylabel('Amplitude')
# cnt+=1


# scaled=[2+3,(2+4)*.1]
# for i in range(2):
#   scale=scaled[i]
#   time_scale = np.linspace(-origin * scale, (len(signal) - origin) * scale, len(signal))
#   plt.subplot(3, 2, cnt)
#   plt.stem(time_scale, signal, 'c+')
#   if i==0:
#     plt.title('Stretched Signal')
#   else:
#     plt.title('Compressed Signal')
#   plt.xlabel('Time')
#   plt.ylabel('Amplitude')
#   cnt+=1


# plt.tight_layout()
# plt.show()