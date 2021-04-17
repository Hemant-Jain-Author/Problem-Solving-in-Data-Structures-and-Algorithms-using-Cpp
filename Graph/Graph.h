
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <limits>
#include <queue>
#include <functional>

class Graph
{
private:
    struct Edge
    {
        int destination;
        int cost;
        Edge(int dst, int cst);
    };

    int count;
    std::vector<std::vector<Edge>> Adj;

    class EdgeComparator
    {
    public:
        bool operator()(Edge *x, Edge *y);
    };

public:
    Graph(int cnt);

    virtual void addDirectedEdge(int source, int destination, int cost);
    virtual void addDirectedEdge(int source, int destination);
    virtual void addUndirectedEdge(int source, int destination, int cost); // bi
    virtual void addUndirectedEdge(int source, int destination); // bi directional edge
    virtual void print();
    // Other Methods of graph.

    void dfsRec(int index, std::vector<bool> &visited);
    bool dfsStack(int source, int target);
    bool dfs(int source, int target);
    void dfsUtil(int index, std::vector<bool> &visited);
    bool bfs(int source, int target);
    void dfsUtil2(int index, std::vector<bool> &visited, std::stack<int> &stk);
    void topologicalSort();
    bool pathExist(int source, int dest);
    int countAllPathdfs(std::vector<bool> &visited, int source, int dest);
    int countAllPath(int src, int dest);
    void printAllPathdfs(std::vector<bool> &visited, int source, int dest, std::stack<int> &path);
    void printAllPath(int src, int dest);
    int rootVertex();
    void transitiveClosureUtil(int source, int dest, std::vector<std::vector<int>> &tc);
    void transitiveClosure(std::vector<std::vector<int>> &tc);
    int bfsDistance(int source, int dest);
    void bfsLevelNode(int source);
    bool isCyclePresentUndirectedDFS(int index, int parentIndex, std::vector<bool>& visited);
    bool isCyclePresentUndirected();
    bool isCyclePresentDFS(int index, std::vector<bool>& visited, std::vector<int>& marked);
    bool isCyclePresent();
    bool isCyclePresentDFSColor(int index, std::vector<int>& visited);
    bool isCyclePresentColor();
    void transposeGraph(Graph&);
    bool isConnectedUndirected();
    bool isStronglyConnected();
    void stronglyConnectedComponent();
    static int heightTreeParentArr(int arr[], int count);
    bool isConnected();
    int isEulerian();
    bool isStronglyConnected2();
    bool isEulerianCycle();
    void prims();
    void dijkstra(int source);
    void shortestPath(int source);// unweighted graph
    void bellmanFordshortestPath(int source);
    int bestFirstSearchPQ(int source, int dest);
};
