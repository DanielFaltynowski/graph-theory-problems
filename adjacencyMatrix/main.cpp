#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> >& matrix, int length);
void createAdjacencyMatrix(vector<vector<int> >& adjacencyMatrix, int verticles);

int main()
{
    int n = 5;
    vector<vector<int> > A(n, vector<int>(n));
    createAdjacencyMatrix(A, n);
    printMatrix(A, n);
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