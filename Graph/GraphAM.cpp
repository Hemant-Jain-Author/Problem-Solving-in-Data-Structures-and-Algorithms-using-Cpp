#include "GraphAM.h"

GraphAM::GraphAM(int cnt) {
	count = cnt;
	adj = std::vector<std::vector<int>>(cnt, std::vector<int>(cnt, 0));
}

void GraphAM::addDirectedEdge(int src, int dst, int cost) {
	adj[src][dst] = cost;
}

void GraphAM::addDirectedEdge(int src, int dst) {
	adj[src][dst] = 1;
}

void GraphAM::addUndirectedEdge(int src, int dst, int cost) {
	addDirectedEdge(src, dst, cost);
	addDirectedEdge(dst, src, cost);
}

void GraphAM::addUndirectedEdge(int src, int dst) {
	addUndirectedEdge(src, dst, 1);
}

void GraphAM::print() {
	for (int i = 0; i < count; i++) {
		std::cout << "Vertex " << i << " is connected to : ";
		for (int j = 0; j < count; j++) {
			if (adj[i][j] != 0)
				std::cout << j << "(cost: " << adj[i][j] << ") ";
		}
		std::cout << std::endl;
	}
}

// Testing code.
int main1() {
	GraphAM graph = GraphAM(4);
	graph.addUndirectedEdge(0, 1);
	graph.addUndirectedEdge(0, 2);
	graph.addUndirectedEdge(1, 2);
	graph.addUndirectedEdge(2, 3);
	graph.print();
	return 0;
}

/*
Vertex 0 is connected to : 1(cost: 1) 2(cost: 1) 
Vertex 1 is connected to : 0(cost: 1) 2(cost: 1) 
Vertex 2 is connected to : 0(cost: 1) 1(cost: 1) 3(cost: 1) 
Vertex 3 is connected to : 2(cost: 1) 
 */

bool GraphAM::EdgeComparator::operator()(Edge *x, Edge *y) {
	if (x->cost <= y->cost) {
		return false;
	}
	return true;
}

void printPathUtil(std::vector<int> &previous, int source, int dest) {
    if (dest == source)
    	std::cout << source;
    else {
        printPathUtil(previous, source, previous[dest]);
        std::cout << "->" << dest;
    }
}

void printPath(std::vector<int> &previous, std::vector<int> &dist, int count, int source) {
    std::cout << "Shortest Paths : ";
    for (int i = 0; i < count; i++) {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << source << "->" << i << " @ Unreachable" << std::endl;
        else if(i != previous[i]) {
            std::cout << "(";
            printPathUtil(previous, source, i);
            std::cout << " @ " << dist[i] << ") ";
        }
    }
    std::cout << std::endl;
}

void GraphAM::dijkstra(int source) {
	std::vector<int> previous(count, -1);
	std::vector<int> dist(count, std::numeric_limits<int>::max());
	std::vector<bool> visited(count, false);

	dist[source] = 0;
	previous[source] = source;

	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;
	Edge *node = new Edge(source, 0);
	queue.push(node);

	while (queue.empty() != true) {
		node = queue.top();
		queue.pop();
		int src = node->dest;
		visited[src] = true;
		for (int dest = 0; dest < count; dest++) {
			int cost = adj[src][dest];
			if (cost != 0) {
				int alt = cost + dist[src];
				if (dist[dest] > alt && visited[dest] == false) {
					dist[dest] = alt;
					previous[dest] = src;
					node = new Edge(dest, alt);
					queue.push(node);
				}
			}
		}
	}

	printPath(previous, dist, count, source);
}

void GraphAM::primsMST() {
	std::vector<int> previous(count, -1);
	std::vector<int> dist(count, std::numeric_limits<int>::max());
	std::vector<bool> visited(count, false);

	int source = 0;
	dist[source] = 0;
	previous[source] = -1;
	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;
	Edge *node = new Edge(source, 0);
	queue.push(node);

	while (queue.empty() != true) {
		node = queue.top();
		queue.pop();
		source = node->dest;
		visited[source] = true;
		for (int dest = 0; dest < count; dest++) {
			int cost = adj[source][dest];
			if (cost != 0) {
				int alt = cost;
				if (dist[dest] > alt && visited[dest] == false) {
					dist[dest] = alt;
					previous[dest] = source;
					node = new Edge(dest, alt);
					queue.push(node);
				}
			}
		}
	}

	// printing result.
	int total = 0;
	std::cout << "Edges are ";
	for (int i = 0; i < count; i++) {
		if (dist[i] == std::numeric_limits<int>::max())
			std::cout << "(" << previous[i] << ", " << i << ", "
					<< "infinity) ";
		else if (previous[i] != -1)
			std::cout << "(" << previous[i] << ", " << i << ", " << dist[i]
					<< ") ";
		total += dist[i];
	}
	std::cout << "\nTotal MST cost: " << total << std::endl;
}

// Testing code.
int main2() {
	GraphAM gph = GraphAM(9);
	gph.addUndirectedEdge(0, 1, 4);
	gph.addUndirectedEdge(0, 7, 8);
	gph.addUndirectedEdge(1, 2, 8);
	gph.addUndirectedEdge(1, 7, 11);
	gph.addUndirectedEdge(2, 3, 7);
	gph.addUndirectedEdge(2, 8, 2);
	gph.addUndirectedEdge(2, 5, 4);
	gph.addUndirectedEdge(3, 4, 9);
	gph.addUndirectedEdge(3, 5, 14);
	gph.addUndirectedEdge(4, 5, 10);
	gph.addUndirectedEdge(5, 6, 2);
	gph.addUndirectedEdge(6, 7, 1);
	gph.addUndirectedEdge(6, 8, 6);
	gph.addUndirectedEdge(7, 8, 7);

	gph.dijkstra(0);
	gph.primsMST();
	return 0;
}

/*
Shortest Paths : (0->1 @ 4) (0->1->2 @ 12) (0->1->2->3 @ 19) (0->7->6->5->4 @ 21) (0->7->6->5 @ 11) (0->7->6 @ 9) (0->7 @ 8) (0->1->2->8 @ 14) 


Edges are (0, 1, 4) (5, 2, 4) (2, 3, 7) (3, 4, 9) (6, 5, 2) (7, 6, 1) (0, 7, 8) (2, 8, 2) 
Total MST cost: 37
 */

bool GraphAM::hamiltonianPathUtil(std::vector<int> &path, int pSize,
		std::vector<int> &added) {
	// Base case full length path is found
	if (pSize == count) {
		return true;
	}
	for (int vertex = 0; vertex < count; vertex++) {
		// there is a path from last element and next vertex
		// and next vertex is not already included in path.
		if (pSize == 0
				|| (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0)) {
			path[pSize++] = vertex;
			added[vertex] = 1;
			if (hamiltonianPathUtil(path, pSize, added))
				return true; // backtracking

			pSize--;
			added[vertex] = 0;
		}
	}
	return false;
}

bool GraphAM::hamiltonianPath() {
	std::vector<int> path(count);
	std::vector<int> added(count);

	if (hamiltonianPathUtil(path, 0, added)) {
		std::cout << "\nHamiltonian Path found :: ";
		for (int i = 0; i < count; i++)
			std::cout << " " << path[i];

		return true;
	}
	std::cout << "\nHamiltonian Path not found";
	return false;
}

// Testing code.
int main3() {
	int count = 5;
	GraphAM graph = GraphAM(count);
	std::vector<std::vector<int>> adj = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 },
			{ 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 }, { 0, 1, 1, 1, 0 } };

	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (adj[i][j] == 1)
				graph.addDirectedEdge(i, j, 1);

	graph.hamiltonianPath();

	GraphAM graph2 = GraphAM(count);
	std::vector<std::vector<int>> adj2 = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 },
			{ 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 0 }, { 0, 1, 1, 0, 0 } };
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (adj2[i][j] == 1)
				graph2.addDirectedEdge(i, j, 1);

	graph2.hamiltonianPath();
	return 0;
}

/*
 Hamiltonian Path found ::  0 1 2 4 3
 Hamiltonian Path found ::  0 3 1 2 4
 */

bool GraphAM::hamiltonianCycleUtil(std::vector<int> &path, int pSize,
		std::vector<int> &added) {
	// Base case full length path is found
	// this last check can be modified to make it a path.
	if (pSize == count) {
		if (adj[path[pSize - 1]][path[0]] == 1) {
			path[pSize] = path[0];
			return true;
		} else
			return false;
	}
	for (int vertex = 0; vertex < count; vertex++) {
		// there is a path from last element and next vertex
		if (pSize == 0
				|| (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0)) {
			path[pSize++] = vertex;
			added[vertex] = 1;
			if (hamiltonianCycleUtil(path, pSize, added))
				return true;
			// backtracking
			pSize--;
			added[vertex] = 0;
		}
	}
	return false;
}

bool GraphAM::hamiltonianCycle() {
	std::vector<int> path(count + 1);
	std::vector<int> added(count);

	if (hamiltonianCycleUtil(path, 0, added)) {
		std::cout << "\nHamiltonian Cycle found :: ";
		for (int i = 0; i <= count; i++)
			std::cout << " " << path[i];
		return true;
	}
	std::cout << "\nHamiltonian Cycle not found";
	return false;
}

// Testing code.
int main4() {
	int count = 5;
	GraphAM graph = GraphAM(count);
	std::vector<std::vector<int>> adj = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 },
			{ 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 }, { 0, 1, 1, 1, 0 } };

	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (adj[i][j] == 1)
				graph.addDirectedEdge(i, j, 1);
	graph.hamiltonianCycle();

	GraphAM graph2 = GraphAM(count);
	std::vector<std::vector<int>> adj2 = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 },
			{ 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 0 }, { 0, 1, 1, 0, 0 } };
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (adj2[i][j] == 1)
				graph2.addDirectedEdge(i, j, 1);

	graph2.hamiltonianCycle();
	return 0;
}

/*
 Hamiltonian Cycle found ::  0 1 2 4 3 0
 Hamiltonian Cycle not found
 */

// Testing code.
int main() {
	main1();
	main2();
	main3();
	main4();
	return 0;
}
