#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void printMatrix(vector<vector<int> >& matrix);
void createAdjacencyMatrix(vector<vector<int> >& adjacencyMatrix, int verticles);
int setVerticles();
void setEdge(vector<vector<int> >& adjacencyMatrix, bool directed);
void deleteVerticle(vector<vector<int> >& adjacencyMatrix, int verticle);
void deleteEdge(vector<vector<int> >& adjacencyMatrix, bool directed);
void exportGraph(int verticles, vector<vector<int> >& adjacencyMatrix);
void dfs(vector<vector<int> > adjacencyMatrix, int verticles, int verticle, vector<int>& visited, vector<int>& spanningTree);
void spanningTree(vector<vector<int> > adjacencyMatrix, int verticles);
void showMenu();
void pressAnyKey();


int main()
{
    int verticles = setVerticles();
    bool directed = false;
    int number;
    vector<int> results;

    vector<vector<int> > A(verticles, vector<int>(verticles));
    createAdjacencyMatrix(A, verticles);

    while(true)
    {
        showMenu();
        int option;
        cin >> option;
        cout << endl;

        switch(option)
        {
            case 1:
                printMatrix(A);
                pressAnyKey();
                break;
            case 2:
                pressAnyKey();
                break;
            case 3:
                cout << "How many edges do you want to add?:" << endl;
                cin >> number;
                for (int i = 0; i < number; i++)
                {
                    setEdge(A, directed);
                }
                pressAnyKey();
                break;
            case 4:
                deleteVerticle(A, verticles);
                pressAnyKey();
                break;
            case 5:
                deleteEdge(A, directed);
                pressAnyKey();
                break;
            case 6:
                spanningTree(A, verticles);
                pressAnyKey();
                break;
            case 7:
                exportGraph(verticles, A);
                return 0;
            default:
                cout << "You prompted an incorrect number!" << endl << endl;
                pressAnyKey();
        }
    }
}

void printMatrix(vector<vector<int> >& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
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

    cout << "Enter the number of vertices: " << endl;
    cin >> verticles;

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

void deleteVerticle(vector<vector<int> >& adjacencyMatrix, int verticle)
{
    adjacencyMatrix.erase(adjacencyMatrix.begin() + verticle);

    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + verticle);
    }
}

void deleteEdge(vector<vector<int> >& adjacencyMatrix, bool directed)
{
    int out;
    int in;

    cout << "Enter an outgoing vertex: ";
    cin >> out;

    cout << "Enter an incoming vertex: ";
    cin >> in;

    if (adjacencyMatrix[out][in] > 0)
    {
        if (!directed && adjacencyMatrix[in][out] > 0)
        {
            adjacencyMatrix[out][in] = adjacencyMatrix[out][in] - 1;
            adjacencyMatrix[in][out] = adjacencyMatrix[in][out] - 1;
        }
        else
        {
            adjacencyMatrix[out][in] = adjacencyMatrix[out][in] - 1;
        }
    }
}

void exportGraph(int verticles, vector<vector<int> >& adjacencyMatrix)
{
    ofstream FileVerticles("verticles.txt");

    if (FileVerticles.is_open())
    {
        FileVerticles << verticles;
        FileVerticles.close();
    }

    ofstream FileEdges("edges.txt");

    if (FileEdges.is_open())
    {
        for (int i = 0; i < verticles; i++)
        {
            for (int j = 0; j < verticles; j++)
            {
                FileEdges << adjacencyMatrix[i][j] << "\n";
            }
        }
        FileEdges.close();
    }
}

void dfs(vector<vector<int> > adjacencyMatrix, int verticles, int verticle, vector<int>& visited, vector<int>& spanningTree)
{
    visited[verticle] = 1;
    for (int i = 0; i < verticles; i++)
    {
        if (adjacencyMatrix[verticle][i] != 0)
        {
            if (visited[i] == 0)
            {
                spanningTree.push_back(verticle);
                spanningTree.push_back(i);
                dfs(adjacencyMatrix, verticles, i, visited, spanningTree);
            }
        }
    }
}

void spanningTree(vector<vector<int> > adjacencyMatrix, int verticles)
{
    vector<int> visited;
    vector<int> spanningTree;
    for (int i = 0; i < verticles; i++)
    {
        visited.push_back(0);
    }

    dfs(adjacencyMatrix, verticles, 0, visited, spanningTree);

    for (int i = 0; i < spanningTree.size(); i++)
    {
        cout << spanningTree[i] << " ";
    }
    cout << endl << endl;

    ofstream FileSpanningTree("spanningTree.txt");

    if (FileSpanningTree.is_open())
    {
        for (int i = 0; i < spanningTree.size(); i++)
        {
            FileSpanningTree << spanningTree[i] << "\n";
        }
        FileSpanningTree.close();
    }
}

void showMenu()
{
    cout << "----------------------------------------" << endl;
    cout << "Select an option:"
         << "\n\t1) Print adjancency matrix."
         << "\n\t2) Add a verticle."
         << "\n\t3) Add an edge"
         << "\n\t4) Delete a verticle."
         << "\n\t5) Delete an edge."
         << "\n\t6) Algorithm DFS."
         << "\n\t7) Exit." << endl << endl;
}

void pressAnyKey()
{
    string temp;
    cout << endl << "Press any key to continue!" << endl << endl;
    getline(cin, temp);
    getline(cin, temp);
}