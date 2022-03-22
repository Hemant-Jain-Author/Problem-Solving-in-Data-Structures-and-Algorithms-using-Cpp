#include <string>
#include <vector>
#include <iostream>
#include <limits>

int tspUtil(std::vector<std::vector<int>> &graph, int n, std::vector<int> &path,
		int pSize, int pCost, std::vector<bool> &visited, int ans) {
	int curr = path[n - 1];
	if (pSize == n && graph[curr][0] > 0) {
		ans = std::min(ans, pCost + graph[curr][0]);
		return ans;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == false && graph[curr][i] > 0) {
			visited[i] = true;
			path[pSize] = i;
			ans = tspUtil(graph, n, path, pSize + 1, pCost + graph[curr][i],
					visited, ans);
			visited[i] = false;
		}
	}
	return ans;
}

int tsp(std::vector<std::vector<int>> &graph, int n) {
	std::vector<bool> visited(n);
	std::vector<int> path(n);
	path[0] = 0;
	visited[0] = true;
	int ans = std::numeric_limits<int>::max();
	ans = tspUtil(graph, n, path, 1, 0, visited, ans);
	return ans;
}

// Testing code.
int main() {
	int n = 4;
	std::vector<std::vector<int>> graph = { { 0, 10, 15, 20 },
			{ 10, 0, 35, 25 }, { 15, 35, 0, 30 }, { 20, 25, 30, 0 } };
	std::cout << "Minimum path cost : " << tsp(graph, n) << std::endl;
	return 0;
}
/*
 Minimum path cost : 65
 */
