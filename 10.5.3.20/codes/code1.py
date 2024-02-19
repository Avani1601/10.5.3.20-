import numpy as np
import matplotlib.pyplot as plt

# Load the data from values.dat
data = np.loadtxt("values.dat")

# Generate the sequence of u(n)
u_n = np.zeros(11)
u_n[0:] = 1

# Convolve y(n) with u(n)
convolved_data = np.convolve(data, u_n, mode='full')[:11]

# Plot the scatter plot of convolved data
plt.scatter(range(11), convolved_data, label='Convolved Data')

# Plot the stem plot of y(n)
plt.stem(range(11), data, label='y(n)', linefmt='b-', markerfmt='bo', basefmt=' ')

plt.xlabel('n')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()

