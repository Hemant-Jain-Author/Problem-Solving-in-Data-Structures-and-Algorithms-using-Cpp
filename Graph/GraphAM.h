#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <limits>
#include <queue>
#include <functional>

class GraphAM
{
private:
    int count;
    std::vector<std::vector<int>> adj;
    struct Edge
    {
        int dest;
        int cost;
        Edge(int dst, int cst)
        {
            dest = dst;
            cost = cst;
        }
    };

    class EdgeComparator
    {
    public:
        bool operator()(Edge *x, Edge *y);
    };


public:
    GraphAM(int cnt);
    void addDirectedEdge(int src, int dst);
    void addDirectedEdge(int src, int dst, int cost);
    void addUndirectedEdge(int src, int dst);
    void addUndirectedEdge(int src, int dst, int cost);
    void print();
    //Other Methods.
};

    void dijkstra(int source);
    void prims();
    bool hamiltonianPath();
    bool hamiltonianPathUtil(std::vector<int>& path, int pSize, std::vector<int>& added);
    bool hamiltonianCycle();
    bool hamiltonianCycleUtil(std::vector<int>& path, int pSize, std::vector<int>& added);

};
