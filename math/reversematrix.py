# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

# Tuntien sähköpiirin ratkaisu 
# Pythonin NumPy:llä

import numpy as np

# Sähköpiiriä vastaava kerroinmatriisi
A = np.array([[0, 6, 4],[3, -3, 2], [0, 3, 2]])

# Käänteismatriisin laskenta ja tulostus
invA = np.linalg.inv(A)
print(invA)

# "Oikean puolen vakiovektori" 
# (Jännitteet voltteina)
b = np.array([[0], [8], [16]])

# Virtojen ratkaisu ja tulostus
#print("Virrat ampeereina: ")
#print(invA@b)

