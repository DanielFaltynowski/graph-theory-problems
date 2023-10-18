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
    with open('spanningTree.txt', "r") as FileEdges:
        data = []
        for datum in FileEdges:
            data.append(int(datum))
        FileEdges.close()
    return data


def create_list_of_edges(data):
    edges = []
    for i in range(0, len(data), 2):
        edges.append((data[i], data[i + 1]))
    return edges


if __name__ == "__main__":
    if os.path.exists('verticles.txt') and os.path.exists('edges.txt'):
        verticles = import_verticles()
        n = len(verticles)
        edges = import_edges()
        edges = create_list_of_edges(edges)
        G = networkx.Graph()
        G.add_nodes_from(verticles)
        G.add_edges_from(edges)

        networkx.draw(G)
        plt.show()
    else:
        print("There is no data to read. First, run the main.cpp program.")
