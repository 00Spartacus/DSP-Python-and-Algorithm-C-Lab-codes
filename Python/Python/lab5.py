# 1
import numpy as np
import scipy.signal as signal
import matplotlib.pyplot as plt
n=np.arange(0,10)
x=np.ones_like(n)
numerator,denominator =signal.zpk2tf([0],[0,-1,-2],1)
zeros,poles,gain=signal.tf2zpk(numerator,denominator)
plt.scatter(np.real(zeros),np.imag(zeros),marker='o',color='blue',label='zeros')
plt.scatter(np.real(poles),np.imag(poles),marker='x',color='red',label='poles')
plt.axhline(0,color='black',linestyle='--')
plt.axvline(0,color='black',linestyle='--')
plt.xlabel('Real')
plt.ylabel('Imaginery')
plt.title('Z-Transform Poles and Zeros')
plt.legend()
plt.grid()
plt.show()

# 2
from scipy import signal
x=[1,1,1,1,1]
def ztransform(x,z):
  X=0
  for n in range(len(x)):
    X+=x[n]*(z**(-n))
  return X
z=1
X=ztransform(x,z)
print(X)
print(X.real)

# 3
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

# 4
import numpy as np
import matplotlib.pyplot as plt

n = np.arange(0, 10)
x = np.array([1, 2, 3, 4, 5, 0, 0, 0, 0, 0])
r = 1.0
omega = np.linspace(0, 2 * np.pi, 50)
z = r * np.exp(1j * omega)

X_z = []
for zi in z:
    Xz = sum(x[k] * zi**(-k) for k in range(len(x)))  # Corrected calculation
    X_z.append(Xz)

X_z = np.array(X_z)
print(X_z)
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.plot(omega,np.abs(X_z))
plt.title("Magnitude of Z-transform")
plt.xlabel("Frequency (rad/s)")
plt.ylabel("|X(z)|")
plt.grid()
plt.subplot(1,2,2)
plt.plot(omega,np.angle(X_z))
plt.title("Phase of Z-transform")
plt.xlabel("Frequency (rad/s)")
plt.ylabel("Phase(radians)")
plt.grid()
plt.tight_layout()
plt.show()

# 5
def ztransform(x,z,origin):
  X=0
  for n in range(len(x)):
    X+=x[n]*(z**(-(n-origin)))
    print(f"{x[n]} z^{n-origin}")
  return X
x=[1,2,3,4,5,6,7,8,9]
origin=4
z=1
X=ztransform(x,z,origin)
print(X)
x=[-1,-2,-3,-4,-5,-6,-7,-8,-9]
origin=8
z=1
X=ztransform(x,z,origin)
print(X)