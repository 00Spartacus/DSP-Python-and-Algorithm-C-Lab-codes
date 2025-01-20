import numpy as np
import matplotlib.pyplot as plt
#Continuous signal parameters
f_signal=5 #frequency of the signal in hz
t=np.linspace(0,1,1000)#Continuous time over
signal= np.sin(2*np.pi*f_signal*t) #continuous
#plot the continuous signal
plt.figure(figsize=(12,2))
plt.plot(t,signal,label='Continuous Signal(5 Hz)',color='Blue')
plt.title('Original Continuous Signal')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.grid()
plt.legend()
plt.show()
# sampling_rates=[10,20,50]
# for sr in sampling_rates:
#   t_sampled= np.arange(0,1,1/sr)
#   sampled_signal=np.sin(2*np.pi*f_signal*t_sampled)
#   plt.figure(figsize=(12,2))
#   plt.stem(t_sampled,sampled_signal,linefmt='b-',markerfmt='bo',basefmt='r-',label=f'Sampled Signal ({sr} Hz)')
#   #plt.plot(t_sampled,sampled_signal,label=f'Sampled Signal ({sr} Hz)',color='Red')
#   plt.title(f'Sampled Signal at {sr} Hz')
#   plt.xlabel('Time (s)')
#   plt.ylabel('Amplitude')
#   plt.grid()  
#   plt.show()
# for i,sr in enumerate(sampling_rates):
#     #sample the signal
#     t_sampled= np.arange(0,1,1/sr)
#     sampled_signal=np.sin(2*np.pi*f_signal*t_sampled)
#     plt.subplot(len(sampling_rates)+1,1,i+2)
#     plt.stem(t_sampled,sampled_signal,linefmt='b-',markerfmt='bo',basefmt='r-',label=f'Sampled Signal ({sr} Hz)')
#    # plt.plot(t_sampled,sampled_signal,label=f'Sampled Signal ({sr} Hz)',color='Red')
#     plt.title(f'Sampled Signal at {sr} Hz')
#     plt.xlabel('Time (s)')
#     plt.ylabel('Amplitude')
#     plt.grid()
#     plt.legend()
sample_rate1=8000
sample_rate2=7
frequency_1=3
frequency_2=10
x1=np.arange(0,1,1/sample_rate1)
x2=np.arange(0,1,1/sample_rate1)
x3=np.arange(0,1,1/sample_rate2)
y1=np.cos(2*np.pi*frequency_1*x1)#8000,3
y2=np.cos(2*np.pi*frequency_2*x2)#8000,10
y3=np.cos(2*np.pi*frequency_2*x3)#7,10
plt.plot(x1,y1,color='b',label='3Hz')
plt.plot(x2,y2,color='r',label='10Hz')
plt.scatter(x3,y3,color='g',label='sampled at 7Hz')