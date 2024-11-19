import numpy as np
import matplotlib.pyplot as plt

# Määritellään matriisi A ja vektori b
A = np.array([[0,-1],[1,0]])
B = np.array([1,2])

# Lasketaan matriisin A käänteismatriisi
## A_inv = np.linalg.inv(A)

# Ratkaistaan x vektori kertomalla A_inv ja b
x = np.dot(A, B)

# Plot columns of A as points
plt.plot(A[0, :], A[1, :], 'o', color='blue', label="Columns of A")

# Plot vector B as a point
plt.plot(B[0], B[1], 'o', color='red', label="B")

# Plot result vector x as a point
plt.plot(x[0], x[1], 'o', color='purple', label="x = A*B")

# Labels and legend
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.legend()
plt.title("Plot of A, B, and x")
plt.grid()
plt.show()

# (3,2) alkion poiminta
#print ("Matriisi B:\n ", B)

# Kolmannen rivin toisen sarakkeen alkion poiminta
#b21 = B[2, 1] # because python starts in 0
#print("Alkio: ", b21)


#b2c = B[:, 1] 
#print("2.sarake: ", b2c)

#b3r = B[2, :] 
#print("3.rivi: ", b3r)