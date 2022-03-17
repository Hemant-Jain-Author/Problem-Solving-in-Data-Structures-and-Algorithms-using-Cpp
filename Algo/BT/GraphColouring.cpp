#include <string>
#include <vector>
#include <iostream>

void printSolution(std::vector<int> &colour, int V) {
	std::cout << "Assigned colours are::";
	for (int i = 0; i < V; i++) {
		std::cout << " " << colour[i];
	}
	std::cout << std::endl;
}

bool isSafe2(std::vector<std::vector<bool>> &graph, std::vector<int> &colour,
		int V) {
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (graph[i][j] && colour[j] == colour[i]) {
				return false;
			}
		}
	}
	return true;
}

bool graphColouring2(std::vector<std::vector<bool>> &graph, int V, int m,
		std::vector<int> &colour, int i) {
	if (i == V) {
		if (isSafe2(graph, colour, V)) {
			printSolution(colour, V);
			return true;
		}
		return false;
	}

	// Assign each colour from 1 to m
	for (int j = 1; j <= m; j++) {
		colour[i] = j;
		if (graphColouring2(graph, V, m, colour, i + 1)) {
			return true;
		}
	}
	return false;
}

bool graphColouring2(std::vector<std::vector<bool>> &graph, int V, int m) {
	std::vector<int> colour(V);
	if (graphColouring2(graph, V, m, colour, 0)) {
		return true;
	}
	return false;
}

bool isSafe(std::vector<std::vector<bool>> &graph, int V,
		std::vector<int> &colour, int v, int c) {
	for (int i = 0; i < V; i++) {
		if (graph[v][i] == true && c == colour[i]) {
			return false;
		}
	}
	return true;
}

bool graphColouringUtil(std::vector<std::vector<bool>> &graph, int V, int m,
		std::vector<int> &colour, int i) {
	if (i == V) {
		printSolution(colour, V);
		return true;
	}

	for (int j = 1; j <= m; j++) {
		if (isSafe(graph, V, colour, i, j)) {
			colour[i] = j;
			if (graphColouringUtil(graph, V, m, colour, i + 1)) {
				return true;
			}
		}
	}
	return false;
}

bool graphColouring(std::vector<std::vector<bool>> &graph, int V, int m) {
	std::vector<int> colour(V);
	if (graphColouringUtil(graph, V, m, colour, 0)) {
		return true;
	}
	return false;
}

int main() {
	std::vector<std::vector<bool>> graph = {
			{ false, true, false, false, true }, { true, false, true, false,
					true }, { false, true, false, true, true }, { false, false,
					true, false, true }, { true, true, true, true, false } };
	int V = 5; // Number of vertices
	int m = 4; // Number of colours
	if (!graphColouring2(graph, V, m)) {
		std::cout << "Solution does not exist" << std::endl;
	}
	if (!graphColouring(graph, V, m)) {
		std::cout << "Solution does not exist" << std::endl;
	}
	return 0;
}

/*
 Assigned colours are:: 1 2 1 2 3
 Assigned colours are:: 1 2 1 2 3
 */
