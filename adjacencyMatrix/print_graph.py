import networkx
import matplotlib.pyplot as plt

with open('verticles.txt', "r") as FileVerticles:
    verticles = int(FileVerticles.readline())
    FileVerticles.close()


with open('edges.txt', "r") as FileEdges:
    data = []
    for datum in FileEdges:
        data.append(int(datum))
    adjacency_matrix = []
    FileEdges.close()


for i in range(verticles):
    adjacency_matrix.append([])
for i in range(verticles):
    for j in range(verticles):
        adjacency_matrix[i].append(data[i * verticles + j])


print(adjacency_matrix)
edges = []
for i in range(verticles):
    for j in range(verticles):
        if adjacency_matrix[i][j] != 0:
            for value in range(adjacency_matrix[i][j]):
                edges.append((i, j))


G = networkx.Graph(edges)
networkx.draw(G)
plt.show()
