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
void determineTheVerticlesOutgoingDegree(vector<vector<int> >& adjacencyMatrix, int verticle, vector<int>& results);
void determineTheVerticlesIncomingDegree(vector<vector<int> >& adjacencyMatrix, int verticle, vector<int>& results);
int countMinimalVerticle(vector<int>& results, int verticles);
int countMaximalVerticle(vector<int>& results, int verticles);
int amountOfEvenVerticles(vector<int>& results, int verticles);
int amountOfOddVerticles(vector<int>& results, int verticles);
void showMenu();


int main()
{
    int verticles = setVerticles();
    bool directed;
    vector<int> results;

    cout << "Do you want to create a directed graph?" << endl;
    cout << "\t0) No" << "\n\t1) Yes" << endl << endl;
    cin >> directed;

    vector<vector<int> > A(verticles, vector<int>(verticles));
    createAdjacencyMatrix(A, verticles);

    while(true)
    {
        showMenu();
        int option;
        cin >> option;

        switch(option)
        {
            case 1:
                printMatrix(A);
                break;
            case 2:
                break;
            case 3:
                setEdge(A, directed);
                break;
            case 4:
                deleteVerticle(A, verticles);
                break;
            case 5:
                deleteEdge(A, directed);
                break;
            case 6:
                exportGraph(verticles, A);
                break;
            case 7:
                cout << "Statictics of outgoing verticles!" << endl;
                cout << "\tDegrees:\n";
                determineTheVerticlesOutgoingDegree(A, verticles, results);
                for (int i = 0; i < verticles; i++)
                {
                    cout << "\t\tdeg(" << i << ") = "
                         << "\t\t" << results[i] << endl;
                }
                cout << endl;
                cout << "\tMinimal degree: " << countMinimalVerticle(results, verticles) << endl;
                cout << "\tMaximal degree: " << countMaximalVerticle(results, verticles) << endl;
                cout << "\tAmount of even verticles: " << amountOfEvenVerticles(results, verticles) << endl;
                cout << "\tAmount of odd verticles: " << amountOfOddVerticles(results, verticles) << endl;
                std::sort(results.begin(), results.end());
                cout << "\tSequence of degrees: <";
                for (int i = 0; i < verticles; i++)
                {
                    cout << results[i] << " ";
                }
                cout << ">" << endl << endl;

                cout << "Statictics of incoming verticles!" << endl;
                cout << "\tDegrees:";
                determineTheVerticlesIncomingDegree(A, verticles, results);
                for (int i = 0; i < verticles; i++)
                {
                    cout << "\t\tdeg(" << i << ") = "
                         << "\t\t" << results[i] << endl;
                }
                cout << endl;
                cout << "\tMinimal degree: " << countMinimalVerticle(results, verticles) << endl;
                cout << "\tMaximal degree: " << countMaximalVerticle(results, verticles) << endl;
                cout << "\tAmount of even verticles: " << amountOfEvenVerticles(results, verticles) << endl;
                cout << "\tAmount of odd verticles: " << amountOfOddVerticles(results, verticles) << endl;
                std::sort(results.begin(), results.end());
                cout << "\tSequence of degrees: <";
                for (int i = 0; i < verticles; i++)
                {
                    cout << results[i] << " ";
                }
                cout << ">" << endl << endl;
                break;
            case 8:
                return 0;
            default:
                cout << "You prompted an incorrect number!" << endl << endl;
        }
    }

    return 0;
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

void determineTheVerticlesOutgoingDegree(vector<vector<int> >& adjacencyMatrix, int verticle, vector<int>& results)
{
    results.clear();
    for (int i = 0; i < verticle; i++)
    {
        int sum = 0;
        for (int j = 0; j < verticle; j++)
        {
            sum = sum + adjacencyMatrix[i][j];
        }
        results.push_back(sum);
    }
}

void determineTheVerticlesIncomingDegree(vector<vector<int> >& adjacencyMatrix, int verticle, vector<int>& results)
{
    results.clear();
    for (int i = 0; i < verticle; i++)
    {
        int sum = 0;
        for (int j = 0; j < verticle; j++)
        {
            sum = sum + adjacencyMatrix[j][i];
        }
        results.push_back(sum);
    }
}

int countMinimalVerticle(vector<int>& results, int verticles)
{
    sort(results.begin(), results.end());
    return results[0];
}

int countMaximalVerticle(vector<int>& results, int verticles)
{
    sort(results.begin(), results.end());
    return results[verticles - 1];
}

int amountOfEvenVerticles(vector<int>& results, int verticles)
{
    int result = 0;

    for (int i = 0; i < verticles; i++)
    {
        if (results[i] % 2 == 0)
        {
            result = result + 1;
        }
    }
    return result;
}

int amountOfOddVerticles(vector<int>& results, int verticles)
{
    int result = 0;

    for (int i = 0; i < verticles; i++)
    {
        if (results[i] % 2 != 0)
        {
            result = result + 1;
        }
    }
    return result;
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