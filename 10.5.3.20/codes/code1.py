import matplotlib.pyplot as plt

# Read theoretical data from file
x_theory = []
y_theory = []
with open("theory.dat", "r") as file:
    for line in file:
        y_theory.append(int(line.strip()))

# Generate x values for theoretical data
x_theory = list(range(1, len(y_theory) + 1))

# Plot scatter plot for theoretical data
plt.figure(figsize=(10, 6))  # Increase figure size
plt.scatter(x_theory, y_theory, label='Theoretical Data', s=80)  # Increase marker size for theoretical data

# Plot stem plot for theoretical data
plt.stem(x_theory, y_theory, linefmt='r-', markerfmt='ro', basefmt='r-', label='Stem Plot for Theoretical Data')

# Add labels and legend
plt.xlabel('Index')
plt.ylabel('Value')
plt.legend()

# Show combined plot
plt.grid(True)
plt.show()

