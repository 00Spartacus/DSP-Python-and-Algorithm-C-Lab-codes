import numpy as np
from scipy import signal
import matplotlib.pyplot as plt
def ztransform(x,z):
  X=0
  for n in range(len(x)):
    X+=x[n]*(z**(-n))
  return X
t=np.linspace(0,1,1000)
x=np.sin(2*np.pi*10*t)+0.5*np.sin(2*np.pi*20*t)
z_x=ztransform(x,t)
w,h=signal.freqz(z_x)
fs=1/(t[1]-t[0])
freq=w*fs/(2*np.pi)
plt.plot(freq,np.abs(w))
plt.xlabel("Frequency(hz)")
plt.ylabel("Magnitude")
plt.title("Frequency Spectrum")
plt.show()