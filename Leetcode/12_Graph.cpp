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

/// <summary>
/// 省份数量
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
/// 所有可能的路径
/// </summary>
/// 有向无环图DAG
vector<vector<int>> result; // 收集符合条件的路径
vector<int> path; // 0节点到终点的路径
// x：目前遍历的节点
// graph：存当前的图
void dfs(vector<vector<int>>& graph, int x) {
    // 要求从节点 0 到节点 n-1 的路径并输出，所以是 graph.size() - 1
    if (x == graph.size() - 1) { // 找到符合条件的一条路径
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[x].size(); i++) { // 遍历节点n链接的所有节点
        path.push_back(graph[x][i]); // 遍历到的节点加入到路径中来
        dfs(graph, graph[x][i]); // 进入下一层递归
        path.pop_back(); // 回溯，撤销本节点
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    path.push_back(0); // 无论什么路径已经是从0节点出发
    dfs(graph, 0); // 开始遍历
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