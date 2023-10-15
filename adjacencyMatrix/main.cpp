#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void printMatrix(vector<vector<int> >& matrix, int length);
void createAdjacencyMatrix(vector<vector<int> >& adjacencyMatrix, int verticles);
int setVerticles();
void setEdge(vector<vector<int> >& adjacencyMatrix, bool directed);

int main()
{
    int verticles = setVerticles();
    vector<vector<int> > A(verticles, vector<int>(verticles));
    createAdjacencyMatrix(A, verticles);
    printMatrix(A, verticles);
    setEdge(A, false);
    printMatrix(A, verticles);

    return 0;
}

void printMatrix(vector<vector<int> >& matrix, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void createAdjacencyMatrix(vector<vector<int> >& adjacencyMatrix, int verticles)
{
    for (int i = 0; i < verticles; i++)
    {
        for (int j = 0; j < verticles; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

int setVerticles()
{
    int verticles;
    ofstream File("verticles.txt");

    cout << "Enter the number of vertices: " << endl;
    cin >> verticles;
    if (File.is_open())
    {
        File << verticles;
        File.close();
    }

    return verticles;
}

void setEdge(vector<vector<int> >& adjacencyMatrix, bool directed)
{
    int out;
    int in;

    cout << "Enter an outgoing vertex: ";
    cin >> out;

    cout << "Enter an incoming vertex: ";
    cin >> in;

    adjacencyMatrix[out][in] = adjacencyMatrix[out][in] + 1;

    if (!directed)
    {
        adjacencyMatrix[in][out] = adjacencyMatrix[in][out] + 1;
    }
}