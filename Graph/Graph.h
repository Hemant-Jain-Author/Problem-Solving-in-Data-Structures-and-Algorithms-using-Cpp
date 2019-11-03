
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
	std::vector<std::vector<Edge*>> Adj;

	class EdgeComparator
	{
	public:
		bool operator()(Edge *x, Edge *y);
	};

public:
	Graph(int cnt);

	virtual void AddDirectedEdge(int source, int destination, int cost);
	virtual void AddDirectedEdge(int source, int destination);
	virtual void AddUnDirectedEdge(int source, int destination, int cost); // bi
	virtual void AddUnDirectedEdge(int source, int destination); // bi directional edge
	virtual void Print();

	// Other Methods of graph.

	void DFSRec(int index, std::vector<bool> &visited);
 	bool DFSStack(int source, int target);
	bool DFS(int source, int target);
	void dfsUtil(int index, std::vector<bool> &visited);
	bool BFS(int source, int target);
	void dfsUtil2(int index, std::vector<bool> &visited, std::stack<int> &stk);
	void TopologicalSort();
	bool PathExist(int source, int dest);
	int countAllPathDFS(std::vector<bool> &visited, int source, int dest);
	int CountAllPath(int src, int dest);
	void printAllPathDFS(std::vector<bool> &visited, int source, int dest, std::stack<int> &path);
	void PrintAllPath(int src, int dest);
	int RootVertex();
    void transitiveClosureUtil(int source, int dest, std::vector<std::vector<int>> &tc);
    void TransitiveClosure(std::vector<std::vector<int>> &tc);
	int bfsDistance(int source, int dest);
	void bfsLevelNode(int source);
	bool isCyclePresentUndirectedDFS(int index, int parentIndex, std::vector<bool>& visited);
    bool isCyclePresentUndirected();
    bool isCyclePresentDFS(int index, std::vector<bool>& visited, std::vector<int>& marked);
    bool isCyclePresent();
    bool isCyclePresentDFSColor(int index, std::vector<int>& visited);
    bool isCyclePresentColor();
	Graph* transposeGraph();
	bool isConnectedUndirected();
	bool isStronglyConnected();
	void stronglyConnectedComponent();
	static int heightTreeParentArr(int arr[], int count);
	bool isConnected();
	int isEulerian();
	bool isStronglyConnected2();
	bool isEulerianCycle();
	void Prims();
	void Dijkstra(int source);
	void ShortestPath(int source);// unweighted graph
	void BellmanFordShortestPath(int source);
	int BestFirstSearchPQ(int source, int dest);
};