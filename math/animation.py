import numpy as np
import matplotlib.pyplot as plt

def piirraAnimaatio2(deltaTheta, T):
    # Rotation matrix for the given angle change
    RdT = np.array([[np.cos(deltaTheta), -np.sin(deltaTheta)], 
                   [np.sin(deltaTheta),  np.cos(deltaTheta)]])

    x0 = np.array([1, 0])

    t = 0
    dt = 0.1
    theta = 0

    fig, ax = plt.subplots(figsize=(6, 6))
    plt.cla()  # Clear the plot
    plt.axis([-2, 2, -2, 2])
    plt.axis('equal')
    plt.grid()
    plt.ion()  # Turn on interactive mode
    
    x = x0

    while t < T:
        x = RdT @ x  # Vector rotation
        plt.plot(x[0], x[1], 'r.')
        plt.plot([0, x[0]], [0, x[1]], 'b-')
        plt.pause(dt)
        t += dt
        
    plt.ioff()  # Turn off interactive mode
    plt.show()
    
piirraAnimaatio2(np.pi / 8, 5)
