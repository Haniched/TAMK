import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# F-letter vertices (explicit F shape)
x = np.array([[1, 1, 1, 2, 2], 
              [3, 2, 1, 3, 2]])

# Rotation pivot point
u = np.array([[0], [3]])

# Animation setup
fig, ax = plt.subplots(figsize=(8, 6))

def rotate_frame(frame):
    # Calculate rotation angle
    t = frame * (2*np.pi/120)
    
    # 2D rotation matrix
    R = np.array([[np.cos(t), -np.sin(t)], 
                  [np.sin(t), np.cos(t)]])
    
    # Rotate points
    y = u + R @ (x - u)
    
    # Clear previous frame
    ax.clear()
    
    # Plot original and rotated points
    ax.plot(x[0, :], x[1, :], 'r.')
    ax.plot(y[0, :], y[1, :], 'b.')
    ax.plot(u[0], u[1], 'g.', markersize=10)
    
    # Plot original lines (red)
    ax.plot([x[0, 0], x[0, 2]], [x[1, 0], x[1, 2]], 'r')  # Left vertical line
    ax.plot([x[0, 0], x[0, 3]], [x[1, 0], x[1, 3]], 'r')  # Top horizontal line
    ax.plot([x[0, 1], x[0, 4]], [x[1, 1], x[1, 4]], 'r')  # Middle horizontal line
    
    # Plot rotated lines (blue)
    ax.plot([y[0, 0], y[0, 2]], [y[1, 0], y[1, 2]], 'b')
    ax.plot([y[0, 0], y[0, 3]], [y[1, 0], y[1, 3]], 'b')
    ax.plot([y[0, 1], y[0, 4]], [y[1, 1], y[1, 4]], 'b')
    
    ax.set_xlim(-2, 2)
    ax.set_ylim(0, 4)
    ax.set_aspect('equal')
    ax.grid(True)
    
    return ax

# Create animation
anim = animation.FuncAnimation(fig, rotate_frame, frames=120, interval=50)

plt.show()