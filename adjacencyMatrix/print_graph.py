import os
import networkx
import matplotlib.pyplot as plt


def import_verticles():
    with open('verticles.txt', "r") as FileVerticles:
        verticles = int(FileVerticles.readline())
        FileVerticles.close()
    response = []
    for i in range(verticles):
        response.append(i)
    return response


def import_edges():
    with open('edges.txt', "r") as FileEdges:
        data = []
        for datum in FileEdges:
            data.append(int(datum))
        adjacency_matrix = []
        FileEdges.close()
    return data


def create_adjacency_matrix(data, verticles):
    adjacency_matrix = []
    for i in range(verticles):
        adjacency_matrix.append([])
    for i in range(verticles):
        for j in range(verticles):
            adjacency_matrix[i].append(data[i * verticles + j])
    return adjacency_matrix


def create_list_of_edges(adjacency_matrix, verticles):
    edges = []
    for i in range(verticles):
        for j in range(verticles):
            if adjacency_matrix[i][j] != 0:
                for value in range(adjacency_matrix[i][j]):
                    edges.append((i, j))
    return edges


if __name__ == "__main__":
    if os.path.exists('verticles.txt') and os.path.exists('edges.txt'):
        verticles = import_verticles()
        n = len(verticles)
        edges = import_edges()
        A = create_adjacency_matrix(edges, n)
        edges = create_list_of_edges(A, n)
        G = networkx.Graph()
        G.add_nodes_from(verticles)
        G.add_edges_from(edges)

        networkx.draw(G)
        plt.show()
    else:
        print("There is no data to read. First, run the main.cpp program.")
