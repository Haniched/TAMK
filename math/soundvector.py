import numpy as np  
import matplotlib.pyplot as plt
import sounddevice as sd
import librosa

# 1
# a = np.array([[3], [4], [5], [6]])
# anorm = np.linalg.norm(a)

# print (anorm)

# 2
# e = np.e # euler 
# b = np.array([[-1.563], [e], [30497], [-986.2]])
# bnorm = np.linalg.norm(b)

# print (bnorm)

# 3
# t = np.arange(1.57, 3.15, 0.02)
# y = np.sin(np.pi * t) + 3 * np.cos(6 * np.pi * t)
#  
# plt.plot(t,y)
# plt.axis((2, 3, -5, 5))
# plt.show()

# 4
# t = np.arange(1.57,3.15,0.00012)
# y = np.sin(50 * 2 * np.pi * t) + 3 * np.cos(440 * 2 * np.pi * t)
# sd.play(y, blocking=True)

# 5
# par = np.random.randint(0, 48, 15)
# 
# plt.plot(par, 'b.')
# plt.show()
# 
# def sqr (vector):
#     return np.sum(vector ** 2)
# 
# my_age = np.full(15, 20)
# distance = np.linalg.norm(par - my_age)
# print (f"Distance of my age: {distance:.2f}")
# print(my_age)
# 
# for _ in range(5):
#     new_vector = np.random.rand(15)
#     new_distance = np.linalg.norm(new_vector - par)
#     print(f"Distance of new random vector from age vector: {new_distance:.2f}")




# 6
#t = np.linspace(0, 2, int(2*3520), False)
#y = np.sin(2*np.pi*1760*t)
#
#sd.play(y, blocking=True)

#7
iwtc = "./iwtc.mp3"
y, sr = librosa.load(iwtc)

sample = int(sr * 1)

start = int(sr*85)

y_sec = y[start:start + sample]
noise = np.random.normal(0,0.1,y_sec.shape)

y_noys = y_sec + noise

sd.play(y_noys, sr)
sd.wait()

plt.plot(y_sec)
plt.show()