import numpy as np
import matplotlib.pyplot as plt

# import the data from the text file
data = np.loadtxt("convolution_data.txt", skiprows=1)

# clear all the previous figures
plt.close("all")

# extract the first 20 terms of the data
n = data[:20, 0]
y_n = data[:20, 1]

# plot the graph
highlight_index = 9
plt.scatter(n[highlight_index], y_n[highlight_index], color='red', marker='o', s=100, label='y(9)')
plt.stem(n, y_n, markerfmt='bo', linefmt='b-', basefmt='r-',label='y(n)') 
# Set labels and title
plt.xlabel('n')
plt.ylabel('y_n')

# Add legend
plt.legend()

plt.savefig("fig2.png")
