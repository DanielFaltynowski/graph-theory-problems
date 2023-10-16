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
bool triangleNaive(vector<vector<int> >& adjacencyMatrix, int verticles);
vector<vector<int> > matrixAdd(const vector<vector<int> >& A, const vector<vector<int> >& B);
vector<vector<int> > matrixSubtract(const vector<vector<int> >& A, const vector<vector<int> >& B);
vector<vector<int> > strassenMatrixMultiply(const vector<vector<int> >& A, const vector<vector<int> >& B);
bool triangleStrassen(vector<vector<int> >& adjacencyMatrix, int verticles);
void showMenu();
void pressAnyKey();


int main()
{
    int verticles = setVerticles();
    bool directed = false;
    bool response;
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
                exportGraph(verticles, A);
                pressAnyKey();
                break;
            case 7:
                response = triangleNaive(A, verticles);
                if (response)
                {
                    cout << "Graph G contains a triangle." << endl << endl;
                }
                else
                {
                    cout << "Graph G does not contains a triangle." << endl << endl;
                }
                response = triangleStrassen(A, verticles);
                if (response)
                {
                    cout << "Graph G contains a triangle." << endl << endl;
                }
                else
                {
                    cout << "Graph G does not contains a triangle." << endl << endl;
                }
                triangleStrassen(A, verticles);
                pressAnyKey();
                break;
            case 8:
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

bool triangleNaive(vector<vector<int> >& adjacencyMatrix, int verticles)
{
    vector<vector<int> > pathsOfTwoMatrix(verticles, vector<int>(verticles));
    createAdjacencyMatrix(pathsOfTwoMatrix, verticles);

    for (int i = 0; i < verticles; i++)
    {
        for (int j = 0; j < verticles; j++)
        {
            for (int k = 0; k < verticles; k++)
            {
                pathsOfTwoMatrix[i][j] = pathsOfTwoMatrix[i][j] + adjacencyMatrix[i][k] * adjacencyMatrix[k][j];
            }
        }
    }
    for (int i = 0; i < verticles; i++)
    {
        for (int j = 0; j < verticles; j++)
        {
            if (adjacencyMatrix[i][j] > 0 && pathsOfTwoMatrix[i][j] > 0)
            {
                return true;
            }
        }
    }
    return false;
}

vector<vector<int> > matrixAdd(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int> > matrixSubtract(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > result(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int> > strassenMatrixMultiply(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int> > C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int m = n / 2;
    vector<vector<int> > A11(m, vector<int>(m, 0));
    vector<vector<int> > A12(m, vector<int>(m, 0));
    vector<vector<int> > A21(m, vector<int>(m, 0));
    vector<vector<int> > A22(m, vector<int>(m, 0));

    vector<vector<int> > B11(m, vector<int>(m, 0));
    vector<vector<int> > B12(m, vector<int>(m, 0));
    vector<vector<int> > B21(m, vector<int>(m, 0));
    vector<vector<int> > B22(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    vector<vector<int> > S1 = strassenMatrixMultiply(matrixAdd(A11, A22), matrixAdd(B11, B22));
    vector<vector<int> > S2 = strassenMatrixMultiply(matrixAdd(A21, A22), B11);
    vector<vector<int> > S3 = strassenMatrixMultiply(A11, matrixSubtract(B12, B22));
    vector<vector<int> > S4 = strassenMatrixMultiply(A22, matrixSubtract(B21, B11));
    vector<vector<int> > S5 = strassenMatrixMultiply(matrixAdd(A11, A12), B22);
    vector<vector<int> > S6 = strassenMatrixMultiply(matrixSubtract(A21, A11), matrixAdd(B11, B12));
    vector<vector<int> > S7 = strassenMatrixMultiply(matrixSubtract(A12, A22), matrixAdd(B21, B22));

    vector<vector<int> > C11 = matrixAdd(matrixSubtract(matrixAdd(S1, S4), S5), S7);
    vector<vector<int> > C12 = matrixAdd(S3, S5);
    vector<vector<int> > C21 = matrixAdd(S2, S4);
    vector<vector<int> > C22 = matrixAdd(matrixAdd(matrixSubtract(S1, S2), S3), S6);

    vector<vector<int> > result(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = C11[i][j];
            result[i][j + m] = C12[i][j];
            result[i + m][j] = C21[i][j];
            result[i + m][j + m] = C22[i][j];
        }
    }

    return result;
}

bool triangleStrassen(vector<vector<int> >& adjacencyMatrix, int verticles)
{
    vector<vector<int> > pathsOfTwoMatrix = strassenMatrixMultiply(adjacencyMatrix, adjacencyMatrix);

    for (int i = 0; i < verticles; i++)
    {
        for (int j = 0; j < verticles; j++)
        {
            if (adjacencyMatrix[i][j] > 0 && pathsOfTwoMatrix[i][j] > 0)
            {
                return true;
            }
        }
    }
    return false;
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
         << "\n\t6) Export graph"
         << "\n\t7) Show statistics."
         << "\n\t8) Exit." << endl << endl;
}

void pressAnyKey()
{
    string temp;
    cout << endl << "Press any key to continue!" << endl << endl;
    getline(cin, temp);
    getline(cin, temp);
}