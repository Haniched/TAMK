import numpy as np
import matplotlib.pyplot as plt

# Define the matrices
XtX_inv = np.array([[20, -16], [-16, 13]])  # (X^T X)^(-1)
Xt = np.array([[1, 1.5], [1, 2]])           # X^T
Y = np.array([[2], [-3]])                   # y_bar

# Calculate b
Xt_Y = np.dot(Xt, Y)                        # X^T * y_bar
b = np.dot(XtX_inv, Xt_Y)                   # (X^T X)^(-1) * (X^T * y_bar)

# print(b)
