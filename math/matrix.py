import numpy as np 

A = np.array( [[-3, 0, -1],[-3,4,1]] )
B = np.array( [[-2,0,4], [2,2,0], [-2,4,-3]] )

C = A@B
print ("Matriisitulo:\n ", C)

# (3,2) alkion poiminta
print ("Matriisi B:\n ", B)

# Kolmannen rivin toisen sarakkeen alkion poiminta
b21 = B[2, 1] # because python starts in 0
print("Alkio: ", b21)


b2c = B[:, 1] 
print("2.sarake: ", b2c)

b3r = B[2, :] 
print("3.rivi: ", b3r)