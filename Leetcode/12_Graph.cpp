#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyMatrix(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int vertex1, int vertex2) {
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1; // 无向图，更新对称位置
    }

    void printAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

//int main() {
//    int numVertices, numEdges;
//
//    cout << "Enter the number of vertices: ";
//    cin >> numVertices;
//    cout << "Enter the number of edges: ";
//    cin >> numEdges;
//
//    Graph graph(numVertices);
//
//    for (int i = 0; i < numEdges; ++i) {
//        int vertex1, vertex2;
//        cout << "Enter edge " << (i + 1) << " (vertex1 vertex2): ";
//        cin >> vertex1 >> vertex2;
//        graph.addEdge(vertex1, vertex2);
//    }
//
//    graph.printAdjacencyMatrix();
//
//    return 0;
//}
