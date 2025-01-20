# 1
import numpy as np
import matplotlib.pyplot as plt
#sampling rate
sr=100
#sampling ibterval
ts=1.0/sr
#sample time
t=np.arange(0,1,ts)
freq=1
x1=3*np.sin(2*np.pi*freq*t)
plt.plot(t,x1)
plt.title("Plot of x(t)")
plt.xlabel("Time")
plt.ylabel("Value of x(t)")
freq=3
x2=1.5*np.sin(2*np.pi*freq*t)
plt.plot(t,x1)
plt.title("Plot of x(t)")
plt.xlabel("Time")
plt.ylabel("Value of x(t)")
freq=6
x3=1*np.sin(2*np.pi*freq*t)
plt.plot(t,x1)
plt.title("Plot of x(t)")
plt.xlabel("Time")
plt.ylabel("Value of x(t)")
x=x1+x2+x3
plt.plot(t,x)
plt.title("Plot of x(t)")
plt.xlabel("Time")
plt.ylabel("Value of x(t)")
# 2
def DFT(x):
  N = len(x)
  print(N)
  X = []
  plt.figure(figsize=(12, 8))
  for k in range(N):
    X_k = 0
    for n in range(0,98):
      e = np.exp(-2j * np.pi * k * n / N)
      X_k += x[n] * e
    X.append(X_k)

  return np.array(X)
x
# 3
D_X=DFT(x)
plt.stem(D_X)
plt.title("Plot of x(t)")
plt.xlabel("Time")
plt.ylabel("Value of x(t)")
# 4
N=32
k=10
c=[]
for n in range(N):
  ck= np.cos((2*np.pi*k*n)/N)
  c.append(ck)
plt.scatter(np.arange(N),c)
plt.plot(c)
plt.title("Cosine Wave")
plt.xlabel("n")
plt.ylabel("Cosine value")
plt.show()
# 5
N=32
k=[0,2,5,10,12,16,20]
plt.figure(figsize=(12,12))
for i in range(len(k)):
  c=[]
  s=[]
  for n in range(N):
    ck=np.cos((2*np.pi*k[i]*n)/N)
    sk=np.sin((2*np.pi*k[i]*n)/N)
    c.append(ck)
    s.append(sk)
  plt.subplot(len(k),2,2*i+1)
  plt.scatter(np.arange(N),c)
  plt.plot(c)
  plt.title("Cosine Wave")
  plt.xlabel("n")
  plt.ylabel("Cosine value")
  plt.subplot(len(k),2,2*i+2)
  plt.scatter(np.arange(N),s)
  plt.plot(s)
  plt.title("Sine Wave")
  plt.xlabel("n")
  plt.ylabel("Sine value")
plt.tight_layout()
plt.show()
# 6
num_t=100
xt=np.zeros(num_t)
xt[:10]=1
plt.plot(xt)
plt.title("Plot of x(t)")
plt.xlabel("Sample index")
plt.ylabel("Value of x(t)")

# 7
fxt=np.fft.fft(xt)
plt.plot(np.fft.fftshift(fxt))
plt.title("Plot FT of x(t)")
plt.ylabel("Magnitude")
plt.xlabel("Frequency Index")

# 8
fxt = np.fft.fft(xt)
# First plot is the real part
plt.subplot(1, 2, 1)
plt.plot(np.real(fxt))
plt.title("Plot of real part of FT of x(t)")
plt.ylabel("Magnitude")
plt.xlabel("Frequency Index")
# Second plot is the imaginary part
plt.subplot(1, 2, 2)
plt.plot(np.imag(fxt))
plt.title("Plot of imaginary part of FT of x(t)")
plt.ylabel("Magnitude")
plt.xlabel("Frequency Index")

# 9
plt.subplot(1,2,1)
plt.plot(np.fft.fftshift(np.abs(fxt)))
plt.title("Magnitude of the FT of x(t)")
plt.ylabel("Magnitude")
plt.xlabel("Frequency Index")
plt.subplot(1,2,2)
plt.plot(np.fft.fftshift(np.angle(fxt)))
plt.title("Angle of the FT of x(t)")
plt.ylabel("Angle")
plt.xlabel("Frequency Index")