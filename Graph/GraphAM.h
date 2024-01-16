#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <limits>
#include <queue>
#include <functional>

class GraphAM {
private:
	int count;
	std::vector<std::vector<int>> adj;
	struct Edge {
		int dest;
		int cost;
		Edge(int dst, int cst) {
			dest = dst;
			cost = cst;
		}
	};

	struct EdgeComparator {
		bool operator()(Edge *x, Edge *y) {
			return (x->cost > y->cost);
		}
	};


public:
	GraphAM(int cnt);
	void addDirectedEdge(int src, int dst, int cost = 1);
	void addUndirectedEdge(int src, int dst, int cost = 1);
	void print();
	//Other Methods.

	void dijkstra(int source);
	void primsMST();
	bool hamiltonianPath();
	bool hamiltonianCycle();

private:
	bool hamiltonianPathUtil(std::vector<int> &path, int pSize,
			std::vector<int> &added);
	bool hamiltonianCycleUtil(std::vector<int> &path, int pSize,
			std::vector<int> &added);
};
