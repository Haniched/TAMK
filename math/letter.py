import numpy as np
import matplotlib.pyplot as plt

# Coordinates for the endpoints of letter 'E'
# x contains the (x, y) coordinates of the endpoints in columns
x = np.array([[1, 1, 1, 2, 2, 2], [1, 2, 3, 1, 2, 3]])

# Rotation angle in radians
t = np.pi / 4  # 45 degrees rotation in radians

# Rotation center point 'u'
u = np.array([[0], [-1]])  # Rotation point for the 'E'
u = np.repeat(u, x.shape[1], axis=1)  # Repeat 'u' for each column in 'x'

# 2D rotation matrix for angle 't'
R = np.array([[np.cos(t), -np.sin(t)], 
              [np.sin(t),  np.cos(t)]])

# Rotate points 'x' around point 'u' by angle 't'
y = u + R @ (x - u)

# Plotting the original and rotated figures
#--------------------

plt.figure()
plt.gca().set_aspect('equal', adjustable='box')  # Keep x and y scales equal
plt.axis([-2, 2, 0, 4])  # Set axis limits
plt.grid()  # Enable grid for easier visualization

# Plot original points of the 'E' in red
plt.plot(x[0, :], x[1, :], 'r.', label="Original Points")

# Plot rotated points of the 'E' in blue
plt.plot(y[0, :], y[1, :], 'b.', label="Rotated Points")

# Plot the rotation center point in green
plt.plot(u[0, 0], u[1, 0], 'go', label="Rotation Center")

# Connect points to form the shape of 'E'
# Original shape (red lines)
plt.plot([x[0, 0], x[0, 2]], [x[1, 0], x[1, 2]], 'r')  # Left vertical line
plt.plot([x[0, 0], x[0, 3]], [x[1, 0], x[1, 3]], 'r')  # Bottom horizontal line
plt.plot([x[0, 1], x[0, 4]], [x[1, 1], x[1, 4]], 'r')  # Middle horizontal line
plt.plot([x[0, 2], x[0, 5]], [x[1, 2], x[1, 5]], 'r')  # Top horizontal line

# Rotated shape (blue lines)
plt.plot([y[0, 0], y[0, 2]], [y[1, 0], y[1, 2]], 'b')  # Left vertical line
plt.plot([y[0, 0], y[0, 3]], [y[1, 0], y[1, 3]], 'b')  # Bottom horizontal line
plt.plot([y[0, 1], y[0, 4]], [y[1, 1], y[1, 4]], 'b')  # Middle horizontal line
plt.plot([y[0, 2], y[0, 5]], [y[1, 2], y[1, 5]], 'b')  # Top horizontal line

# Show the legend and display the plot
plt.legend()
plt.show()
