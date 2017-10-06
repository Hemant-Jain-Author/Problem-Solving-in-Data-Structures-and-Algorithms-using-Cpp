#pragma once

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
		int source;
		int destination;
		int cost;
		Edge *next;

		Edge(int src, int dst, int cst);
	};

	struct AdjList
	{
		Edge *head;
	};

	int count;
	std::vector<AdjList*> ListVector;

	class EdgeComparator
	{
	public:
		bool operator()(Edge *x, Edge *y);
	};

public:
	Graph(int cnt);

	virtual void AddEdge(int source, int destination, int cost);
	virtual void AddEdge(int source, int destination);
	virtual void AddBiEdge(int source, int destination, int cost); // bi
	virtual void AddBiEdge(int source, int destination); // bi directional edge
	virtual void Print();

	// Other Methods of graph.


	void Dijkstra(int source);

	void Prims();

	void Prims2();

	void TopologicalSortDFS(int index, std::vector<int> &visited, std::stack<int> &stk);

	void TopologicalSort();

	int PathExist(int source, int destination);

	void DFSRec(int index, std::vector<int> &visited);

	virtual void DFSStack();

	virtual void DFS();

	virtual void BFSQueue(int index, std::vector<int> &visited);

	virtual void BFS();

	virtual bool isConnected();

	virtual void ShortestPath(int source); // unweighted graph

	virtual void BellmanFordShortestPath(int source);

};