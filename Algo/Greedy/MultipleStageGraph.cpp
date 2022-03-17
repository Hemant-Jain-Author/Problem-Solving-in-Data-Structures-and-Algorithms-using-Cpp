#include <string>
#include <vector>
#include <iostream>
#include <limits>

int INF = std::numeric_limits<int>::max();

int shortestDist(std::vector<std::vector<int>> &graph, int n) {
	// dist[i] is going to store shortest distance from node i to node n-1.
	std::vector<int> dist(n, INF);
	std::vector<int> path(n);
	int value;
	dist[0] = 0;
	path[0] = -1;

	// Calculating shortest path for the nodes
	for (int i = 0; i < n; i++) {
		// Check all nodes of next 
		for (int j = i; j < n; j++) {
			// Reject if no edge exists
			if (graph[i][j] == INF) {
				continue;
			}
			value = graph[i][j] + dist[i];
			if (dist[j] > value) {
				dist[j] = value;
				path[j] = i;
			}
		}
	}
	value = n - 1;
	while (value != -1) {
		std::cout << value << " ";
		value = path[value];
	}
	std::cout << std::endl;
	return dist[n - 1];
}

// Testing code.
int main() {
	// Graph stored in the form of an adjacency Matrix
	std::vector<std::vector<int>> graph = {
			{ INF, 1, 2, 5, INF, INF, INF, INF }, { INF, INF, INF, INF, 4, 11,
					INF, INF }, { INF, INF, INF, INF, 9, 5, 16, INF }, { INF,
					INF, INF, INF, INF, INF, 2, INF }, { INF, INF, INF, INF,
					INF, INF, INF, 18 },
			{ INF, INF, INF, INF, INF, INF, INF, 13 }, { INF, INF, INF, INF,
					INF, INF, INF, 2 },
			{ INF, INF, INF, INF, INF, INF, INF, INF } };

	std::cout << shortestDist(graph, 8) << std::endl;
}
/*
 7 6 3 0
 9
 */
