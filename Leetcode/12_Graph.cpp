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
        adjacencyMatrix[vertex2][vertex1] = 1; // ����ͼ�����¶Գ�λ��
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

/// <summary>
/// ʡ������
/// </summary>
/// 
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities, int i) {
    for (int j = 0; j < cities; j++)
    {
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, visited, cities, j);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();
    vector<int>visited(cities);
    int provinces = 0;
    for (int i = 0; i < cities; i++)
    {
        if (!visited[i]) {
            dfs(isConnected, visited, cities, i);
            provinces++;
        }
    }
    return provinces;
}




/// <summary>
/// ���п��ܵ�·��
/// </summary>
/// �����޻�ͼDAG
vector<vector<int>> result; // �ռ�����������·��
vector<int> path; // 0�ڵ㵽�յ��·��
// x��Ŀǰ�����Ľڵ�
// graph���浱ǰ��ͼ
void dfs(vector<vector<int>>& graph, int x) {
    // Ҫ��ӽڵ� 0 ���ڵ� n-1 ��·��������������� graph.size() - 1
    if (x == graph.size() - 1) { // �ҵ�����������һ��·��
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[x].size(); i++) { // �����ڵ�n���ӵ����нڵ�
        path.push_back(graph[x][i]); // �������Ľڵ���뵽·������
        dfs(graph, graph[x][i]); // ������һ��ݹ�
        path.pop_back(); // ���ݣ��������ڵ�
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    path.push_back(0); // ����ʲô·���Ѿ��Ǵ�0�ڵ����
    dfs(graph, 0); // ��ʼ����
    return result;

}

//int main(){
//
//    vector<vector<int>>graph = { {1,2},{3},{3},{} };
//    result = allPathsSourceTarget(graph);
//
//    for (int i = 0; i < result.size(); i++){
//        for (int j = 0; j < result[0].size(); j++)
//        {
//            cout << result[i][j] << " ";
//        }
//    cout << endl;
//    }
//
//    return 0;
//
//}