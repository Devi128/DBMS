import numpy as np

data = np.array([
    [160, 55],
    [170, 65],
    [165, 60],
    [180, 75]
])

def euclidean_distance(a, b):
    return np.sqrt(np.sum((a - b) ** 2))

num_instances = data.shape[0]
dissimilarity_matrix = np.zeros((num_instances, num_instances))

for i in range(num_instances):
    for j in range(num_instances):
        dissimilarity_matrix[i][j] = euclidean_distance(data[i], data[j])

print("Dissimilarity Matrix (Euclidean Distance):")
print(dissimilarity_matrix)