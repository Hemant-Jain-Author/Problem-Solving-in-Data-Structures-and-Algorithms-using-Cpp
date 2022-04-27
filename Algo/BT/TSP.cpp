#include <string>
#include <vector>
#include <iostream>
#include <limits>

void tspUtil(std::vector<std::vector<int>> &graph, int n, 
			std::vector<int> &path, int pSize, 
			int pCost, std::vector<bool> &visited, 
			int& ans, std::vector<int> &ansPath) {
	
	if(pCost >= ans) // Ignore useless paths.
        return;
	
	int curr = path[pSize - 1];
	if (pSize == n) {
		if(graph[curr][0] > 0 && ans > pCost + graph[curr][0]) {
			path[pSize] = path[0];
			ans = pCost + graph[curr][0];
			ansPath = path;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == false && graph[curr][i] > 0) {
			visited[i] = true;
			path[pSize] = i;
			tspUtil(graph, n, path, pSize + 1, pCost + graph[curr][i], 
			visited, ans, ansPath);
			visited[i] = false;
		}
	}
}

int tsp(std::vector<std::vector<int>> &graph, int n) {
	std::vector<bool> visited(n);
	std::vector<int> path(n+1);
	std::vector<int> ansPath;
	path[0] = 0;
	visited[0] = true;
	int ans = std::numeric_limits<int>::max();
	tspUtil(graph, n, path, 1, 0, visited, ans, ansPath);
	
	std::cout << "Shortest Path weight: " << ans << std::endl;
	std::cout << "Shortest Path: ";
	for (auto i : ansPath)
		std::cout << i << " ";
	std::cout << std::endl;
	return ans;
}

// Testing code.
int main() {
	int n = 4;
	
	std::vector<std::vector<int>> graph = { { 0, 10, 15, 20 }, 
											{ 10, 0, 35, 25 }, 
											{ 15, 35, 0, 30 }, 
											{ 20, 25, 30, 0 } };
					   
	tsp(graph, n);
	return 0;
}
/*
Shortest Path weight: 80
Shortest Path: 0 1 3 2 0 
*/
