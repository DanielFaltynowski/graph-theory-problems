# Adjacency matrix

<br>

One way to represent a graph $G$ with n vertices numbered from $0$ to $n-1$ is by using an adjacency matrix $A$ of size $n \times n$. Then, the successive rows $i$ and columns $j$ represent their corresponding vertices. The position $A_{ij}$ represents the number of directed edges from vertex $i$ to vertex $j$. Let the following graph serve as an example.

<br>

<img src="pictures/graph.png" width="250">

<br>

Then the adjacency matrix $A$ of graph $G$ would look like this.

<img src="pictures/matrix.png" width="245">

<br>

## How to run the project

To run the project, navigate to the `adjacencyMatrix` folder in the console window and use the command `bash start.sh`.

<br>

## Function overview

Below, I describe the operation of individual functions in the program.

<br>

### printMatrix

The function's task is to display the current adjacency matrix $A$ stored in the program's temporary memory. The program sequentially displays all rows in $\Theta(n^2)$ time.

### createAdjacencyMatrix

The function fills the matrix with zeros at a cost of $\Theta(n^2)$.

### setVerticles

The function sets the number of vertices in the graph.

### setEdge

The function creates an edge from vertex $v_1$ to vertex $v_2." This involves updating the existing adjacency matrix with new data.

### deleteVerticle

The function sequentially removes the row and then the column corresponding to the specified vertex. To do this, I use the built-in `erase()` function of the `vector<int>` structure. The computational complexity depends on the vertex being removed; however, in the case of removing elements from the middle of the vector, the computational complexity is very high.

### deleteEdge

The sole task of the function is to update the existing data in the adjacency matrix.

### exportGraph

The function writes the number of vertices to the 'vertices.txt' file and edge data to the 'edges.txt' file. The computational complexity is $\Theta(n^2)$ because the function iterates through the entire adjacency matrix.