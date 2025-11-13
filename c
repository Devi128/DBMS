import matplotlib.pyplot as plt
import numpy as np

data = np.array([
    [160, 55],
    [170, 65],
    [165, 60],
    [180, 75]
])

heights = data[:, 0]
weights = data[:, 1]
names = ['A', 'B', 'C', 'D']

plt.figure(figsize=(6,4))
plt.hist(heights, bins=4, color='skyblue', edgecolor='black')
plt.title("Histogram of Heights")
plt.xlabel("Height (cm)")
plt.ylabel("Frequency")
plt.show()

plt.figure(figsize=(6,4))
plt.boxplot([heights, weights], labels=['Height', 'Weight'])
plt.title("Box Plot of Height and Weight")
plt.show()

plt.figure(figsize=(6,4))
plt.bar(names, weights, color='orange')
plt.title("Bar Chart of Weights")
plt.xlabel("Instances")
plt.ylabel("Weight (kg)")
plt.show()

plt.figure(figsize=(6,6))
plt.pie(weights, labels=names, autopct='%1.1f%%', startangle=90, colors=['red','green','blue','yellow'])
plt.title("Pie Chart of Weights")
plt.show()