#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <limits>
#include <queue>
#include <functional>
#include <algorithm>

// Used in kruskal MST algorithm
class Sets {
public:
	int parent = 0;
	int rank = 0;
	Sets(int p, int r);
};

class Graph {
private:
	struct Edge {
		int src;
		int dest;
		int cost;
		Edge(int src, int dst, int cst);
	};

	int count;
	std::vector<std::vector<Edge>> Adj;

	// Used in priority queue.
	struct EdgeComparator {
		bool operator()(Edge *x, Edge *y) {
			return (x->cost > y->cost);
		}
	};

	// Used in sorting.
	static bool compare(Edge *e1, Edge *e2) {
		return (e1->cost < e2->cost);
	}

public:
	Graph(int cnt);

	void addDirectedEdge(int source, int dest, int cost = 1);
	void addUndirectedEdge(int source, int dest, int cost = 1); // bi directional edge
	void print();
	// Other Methods of graph.

	bool dfs(int source, int target);
	bool bfs(int source, int target);
	bool dfsStack(int source, int target);
	void topologicalSort();
	bool pathExist(int source, int dest);
	int countAllPath(int src, int dest);
	void printAllPath(int src, int dest);
	int rootVertex();
	void transitiveClosure(std::vector<std::vector<int>> &tc);
	void bfsLevelNode(int source);
	int bfsDistance(int source, int dest);
	bool isCyclePresentUndirected();
	bool isCyclePresent();
	bool isCyclePresentColor();
	void transposeGraph(Graph&);
	bool isConnectedUndirected();
	bool isStronglyConnected();
	void stronglyConnectedComponent();
	static int heightTreeParentArr(int arr[], int count);
	static int heightTreeParentArr2(int arr[], int count);
	void dijkstra(int source);
	void primsMST();
	void kruskalMST();
	void shortestPath(int source); // unweighted graph
	void bellmanFordshortestPath(int source);
	int isEulerian();
	bool isEulerianCycle();
	void floydWarshall();

private:
	void dfsRec(int index, std::vector<bool> &visited);
	void dfsUtil(int index, std::vector<bool> &visited);
	void dfsUtil2(int index, std::vector<bool> &visited, std::stack<int> &stk);
	int countAllPathDFS(std::vector<bool> &visited, int source, int dest);
	void printAllPathDFS(std::vector<bool> &visited, int source, int dest,
			std::stack<int> &path);
	void transitiveClosureUtil(int source, int dest,
			std::vector<std::vector<int>> &tc);
	bool isCyclePresentUndirectedDFS(int index, int parentIndex,
			std::vector<bool> &visited);
	bool isCyclePresentDFS(int index, std::vector<bool> &visited,
			std::vector<int> &marked);
	bool isCyclePresentDFSColor(int index, std::vector<int> &visited);
	bool isConnected();
	bool isStronglyConnected2();
	int bestFirstSearchPQ(int source, int dest);
	int find(std::vector<Sets*> &sets, int index);
	void union_Keyword(std::vector<Sets*> &sets, int x, int y); // consider x and y are roots of sets.
	void printSolution(std::vector<std::vector<int>> &cost,
			std::vector<std::vector<int>> &path, int V);
	void printPath2(std::vector<std::vector<int>> &path, int u, int v);
};


