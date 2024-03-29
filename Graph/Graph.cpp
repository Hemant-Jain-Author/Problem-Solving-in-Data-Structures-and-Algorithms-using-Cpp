#include "Graph.h"

Graph::Edge::Edge(int s, int d, int c = 1) {
	src = s;
	dest = d;
	cost = c;
}

Graph::Graph(int cnt) {
	count = cnt;
	Adj = std::vector < std::vector < Edge >> (cnt);
}

void Graph::addDirectedEdge(int source, int dest, int cost) {
	Adj[source].push_back(Edge(source, dest, cost));
}

void Graph::addUndirectedEdge(int source, int dest, int cost) {
	addDirectedEdge(source, dest, cost);
	addDirectedEdge(dest, source, cost);
}

void Graph::print() {
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		std::cout << "Vertex " << i << " is connected to : ";
		for (auto adn : adl)
			std::cout << adn.dest << "(cost: " << adn.cost << ") ";
		std::cout << std::endl;
	}
}

// Testing code.
int main1() {
	Graph gph(4);
	gph.addUndirectedEdge(0, 1);
	gph.addUndirectedEdge(0, 2);
	gph.addUndirectedEdge(1, 2);
	gph.addUndirectedEdge(2, 3);
	gph.print();
	return 0;
}

/*
Vertex 0 is connected to : 1(cost: 1) 2(cost: 1) 
Vertex 1 is connected to : 0(cost: 1) 2(cost: 1) 
Vertex 2 is connected to : 0(cost: 1) 1(cost: 1) 3(cost: 1) 
Vertex 3 is connected to : 2(cost: 1) 
 */

void Graph::dfsUtil(int index, std::vector<bool> &visited) {
	visited[index] = true;
	auto &adl = Adj[index];
	for (auto adn : adl) {
		if (visited[adn.dest] == false)
			dfsUtil(adn.dest, visited);
	}
}

bool Graph::dfs(int source, int target) {
	std::vector<bool> visited(count, false);
	dfsUtil(source, visited);
	return visited[target];
}

bool Graph::dfsStack(int source, int target) {
	std::vector<bool> visited(count, false);
	std::stack<int> stk;
	visited[source] = true;
	stk.push(source);

	int curr;
	while (stk.empty() == false) {
		curr = stk.top();
		stk.pop();
		auto &adl = Adj[curr];
		for (auto adn : adl) {
			if (visited[adn.dest] == false) {
				visited[adn.dest] = true;
				stk.push(adn.dest);
			}
		}
	}
	return visited[target];
}

bool Graph::bfs(int source, int target) {
	std::vector<bool> visited(count, false);
	std::queue<int> que;
	visited[source] = true;
	que.push(source);

	int curr;
	while (que.empty() == false) {
		curr = que.front();
		que.pop();
		auto &adl = Adj[curr];
		for (auto adn : adl) {
			if (visited[adn.dest] == false) {
				visited[adn.dest] = true;
				que.push(adn.dest);
			}
		}
	}
	return visited[target];
}

// Testing code.
int main2() {
	Graph gph(8);
	gph.addUndirectedEdge(0, 3);
	gph.addUndirectedEdge(0, 2);
	gph.addUndirectedEdge(0, 1);
	gph.addUndirectedEdge(1, 4);
	gph.addUndirectedEdge(2, 5);
	gph.addUndirectedEdge(3, 6);
	gph.addUndirectedEdge(6, 7);
	gph.addUndirectedEdge(5, 7);
	gph.addUndirectedEdge(4, 7);

	std::cout << "Path between 0 & 6 : " << gph.dfs(0, 6) << std::endl;
	std::cout << "Path between 0 & 6 : " << gph.bfs(0, 6) << std::endl;
	std::cout << "Path between 0 & 6 : " << gph.dfsStack(0, 6) << std::endl;
	return 0;
}

/*
Path between 0 & 6 : 1
Path between 0 & 6 : 1
Path between 0 & 6 : 1
*/

void Graph::dfsUtil2(int index, std::vector<bool> &visited,
		std::stack<int> &stk) {
	visited[index] = true;
	auto &adl = Adj[index];
	for (auto adn : adl) {
		if (visited[adn.dest] == false)
			dfsUtil2(adn.dest, visited, stk);
	}
	stk.push(index);
}

void Graph::topologicalSort() {
	std::stack<int> stk;
	std::vector<bool> visited(count, false);
	for (int i = 0; i < count; i++) {
		if (visited[i] == false) {
			dfsUtil2(i, visited, stk);
		}
	}

	std::cout << "Topological order of given graph is : ";
	while (stk.empty() != true) {
		std::cout << stk.top() << " ";
		stk.pop();
	}
}

// Testing code.
int main3() {
	Graph gph(9);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(1, 2);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(1, 4);
	gph.addDirectedEdge(3, 2);
	gph.addDirectedEdge(3, 5);
	gph.addDirectedEdge(4, 5);
	gph.addDirectedEdge(4, 6);
	gph.addDirectedEdge(5, 7);
	gph.addDirectedEdge(6, 7);
	gph.addDirectedEdge(7, 8);
	gph.topologicalSort();
	return 0;
}

/*
Topological order of given graph is : 1 4 6 3 5 7 8 0 2 
*/

bool Graph::pathExist(int source, int dest) {
	std::vector<bool> visited(count, false);
	dfsUtil(source, visited);
	return visited[dest];
}

// Testing code.
int main4() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(2, 3);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(3, 4);
	gph.addDirectedEdge(1, 4);
	std::cout << "PathExist :: " << gph.pathExist(0, 4) << std::endl;
	return 0;
}

/*
PathExist :: 1
 */

int Graph::countAllPathDFS(std::vector<bool> &visited, int source, int dest) {
	if (source == dest)
		return 1;
	int count = 0;
	visited[source] = true;
	auto &adl = Adj[source];
	for (auto adn : adl) {
		if (visited[adn.dest] == false) {
			count += countAllPathDFS(visited, adn.dest, dest);
		}
	}
	visited[source] = false;
	return count;
}

int Graph::countAllPath(int src, int dest) {
	std::vector<bool> visited(count, false);
	return countAllPathDFS(visited, src, dest);
}

// Testing code.
int main5() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(2, 3);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(3, 4);
	gph.addDirectedEdge(1, 4);
	std::cout << "Path Count :: " << gph.countAllPath(0, 4) << std::endl;
	return 0;
}

/*
Path Count :: 3
 */

void printStackUtil(std::stack<int> &stk) {
	if (stk.empty() == 1)
		return;
	int temp = stk.top();
	stk.pop();
	std::cout << temp << " ";
	printStackUtil(stk);
	stk.push(temp);
}

void printStack(std::stack<int> &stk) {
	std::cout << "[ ";
	printStackUtil(stk);
	std::cout << "]" << std::endl;
}

void Graph::printAllPathDFS(std::vector<bool> &visited, int source, int dest,
		std::stack<int> &path) {
	path.push(source);
	if (source == dest) {
		printStack(path);
		path.pop();
		return;
	}
	visited[source] = true;
	auto &adl = Adj[source];
	for (auto adn : adl) {
		if (visited[adn.dest] == false) {
			printAllPathDFS(visited, adn.dest, dest, path);
		}
	}
	visited[source] = false;
	path.pop();
}

void Graph::printAllPath(int src, int dest) {
	std::vector<bool> visited(count, false);
	std::stack<int> path;
	printAllPathDFS(visited, src, dest, path);
}

// Testing code.
int main6() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(2, 3);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(3, 4);
	gph.addDirectedEdge(1, 4);
	gph.printAllPath(0, 4);
	return 0;
}

/*
[ 4 3 1 0 ]
[ 4 1 0 ]
[ 4 3 2 0 ]
 */

int Graph::rootVertex() {
	std::vector<bool> visited(count, false);
	int retVal = -1;
	for (int i = 0; i < count; i++) {
		if (visited[i] == false) {
			dfsUtil(i, visited);
			retVal = i;
		}
	}
	std::cout << "Root vertex is :: " << retVal << std::endl;
	return retVal;
}

// Testing code.
int main7() {
	Graph gph(7);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(4, 1);
	gph.addDirectedEdge(6, 4);
	gph.addDirectedEdge(5, 6);
	gph.addDirectedEdge(5, 2);
	gph.addDirectedEdge(6, 0);
	gph.rootVertex();
	return 0;
}

/*
Root vertex is :: 5
 */

void Graph::transitiveClosureUtil(int source, int dest,
		std::vector<std::vector<int>> &tc) {
	tc[source][dest] = 1;
	auto &adl = Adj[dest];
	for (auto adn : adl) {
		if (tc[source][adn.dest] == 0)
			transitiveClosureUtil(source, adn.dest, tc);
	}
}

void Graph::transitiveClosure(std::vector<std::vector<int>> &tc) {
	for (int i = 0; i < count; i++)
		transitiveClosureUtil(i, i, tc);
}

// Testing code.
int main8() {
	Graph gph(4);
	gph.addDirectedEdge(0, 1, 1);
	gph.addDirectedEdge(0, 2, 1);
	gph.addDirectedEdge(1, 2, 1);
	gph.addDirectedEdge(2, 0, 1);
	gph.addDirectedEdge(2, 3, 1);
	gph.addDirectedEdge(3, 3, 1);

	std::vector<std::vector<int>> tc(4, std::vector<int>(4, 0));
	gph.transitiveClosure(tc);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << tc[i][j] << " ";
		std::cout << std::endl;
	}
	return 0;
}

/*
1 1 1 1
1 1 1 1
1 1 1 1
0 0 0 1
 */

void Graph::bfsLevelNode(int source) {
	std::vector<bool> visited(count, false);
	std::vector<int> level(count, 0);
	visited[source] = true;
	std::queue<int> que;
	que.push(source);
	level[source] = 0;
	std::cout << "Node  - Level" << std::endl;

	while (que.empty() == false) {
		int curr = que.front();
		que.pop();

		int depth = level[curr];
		auto &adl = Adj[curr];
		std::cout << curr << " - " << depth << std::endl;
		for (auto adn : adl) {
			if (visited[adn.dest] == false) {
				visited[adn.dest] = true;
				que.push(adn.dest);
				level[adn.dest] = depth + 1;
			}
		}
	}
}

int Graph::bfsDistance(int source, int dest) {
	std::vector<bool> visited(count, false);
	std::queue<int> que;
	que.push(source);
	visited[source] = true;
	std::vector<int> level(count, 0);
	level[source] = 0;

	while (que.empty() == false) {
		int curr = que.front();
		que.pop();
		int depth = level[curr];
		auto &adl = Adj[curr];
		for (auto adn : adl) {
			if (adn.dest == dest)
				return depth + 1;

			if (visited[adn.dest] == false) {
				visited[adn.dest] = true;
				que.push(adn.dest);
				level[adn.dest] = depth + 1;
			}
		}
	}
	return -1;
}

// Testing code.
int main9() {
	Graph gph(7);
	gph.addUndirectedEdge(0, 1, 1);
	gph.addUndirectedEdge(0, 2, 1);
	gph.addUndirectedEdge(0, 4, 1);
	gph.addUndirectedEdge(1, 2, 1);
	gph.addUndirectedEdge(2, 5, 1);
	gph.addUndirectedEdge(3, 4, 1);
	gph.addUndirectedEdge(4, 5, 1);
	gph.addUndirectedEdge(4, 6, 1);
	gph.bfsLevelNode(1);
	std::cout << "BfsDistance(1, 6) :: " << gph.bfsDistance(1, 6) << std::endl;
	return 0;
}

/*
 Node  - Level
 1 - 0
 0 - 1
 2 - 1
 4 - 2
 5 - 2
 3 - 3
 6 - 3
 BfsDistance(1, 6) :: 3
 */

bool Graph::isCyclePresentUndirectedDFS(int index, int parentIndex,
		std::vector<bool> &visited) {
	visited[index] = true;
	int dest;
	auto &adl = Adj[index];
	for (auto adn : adl) {
		dest = adn.dest;
		if (visited[dest] == false) {
			if (isCyclePresentUndirectedDFS(dest, index, visited))
				return true;
		} else if (parentIndex != dest)
			return true;
	}
	return false;
}

bool Graph::isCyclePresentUndirected() {
	std::vector<bool> visited(count, false);
	for (int i = 0; i < count; i++)
		if (visited[i] == false)
			if (isCyclePresentUndirectedDFS(i, -1, visited))
				return true;
	return false;
}

// Testing code.
int main10() {
	Graph gph(6);
	gph.addUndirectedEdge(0, 1, 1);
	gph.addUndirectedEdge(1, 2, 1);
	gph.addUndirectedEdge(3, 4, 1);
	gph.addUndirectedEdge(4, 2, 1);
	gph.addUndirectedEdge(2, 5, 1);
	std::cout << "isCyclePresentUndirected : " << gph.isCyclePresentUndirected()
			<< std::endl;
	gph.addUndirectedEdge(4, 1, 1);
	std::cout << "isCyclePresentUndirected : " << gph.isCyclePresentUndirected()
			<< std::endl;
	return 0;
}

/*
isCyclePresentUndirected : 0
isCyclePresentUndirected : 1
 */


bool Graph::isCyclePresentDFS(int index, std::vector<bool> &visited,
		std::vector<int> &marked) {
	visited[index] = true;
	marked[index] = 1;
	auto &adl = Adj[index];
	for (auto adn : adl) {
		int dest = adn.dest;
		if (marked[dest] == 1)
			return true;

		if (visited[dest] == false)
			if (isCyclePresentDFS(dest, visited, marked))
				return true;
	}
	marked[index] = 0;
	return false;
}

bool Graph::isCyclePresent() {

	std::vector<bool> visited(count, false);
	std::vector<int> marked(count, false);
	for (int index = 0; index < count; index++) {
		if (visited[index] == false)
			if (isCyclePresentDFS(index, visited, marked))
				return true;
	}
	return false;
}

bool Graph::isCyclePresentDFSColor(int index, std::vector<int> &visited) {
	visited[index] = 1; // 1 = grey
	int dest;
	auto &adl = Adj[index];
	for (auto adn : adl) {
		dest = adn.dest;
		if (visited[dest] == 1) // "Grey":
			return true;

		if (visited[dest] == 0) // "White":
			if (isCyclePresentDFSColor(dest, visited))
				return true;
	}
	visited[index] = 2; // "Black"
	return false;
}

bool Graph::isCyclePresentColor() {
	std::vector<int> visited(count, 0);
	for (int i = 0; i < count; i++) {
		if (visited[i] == 0) // "White"
			if (isCyclePresentDFSColor(i, visited))
				return true;
	}
	return false;
}

// Testing code.
int main11() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(2, 3);
	gph.addDirectedEdge(1, 3);
	gph.addDirectedEdge(3, 4);
	gph.addDirectedEdge(4, 1);
	std::cout << "isCyclePresent : " << gph.isCyclePresent() << std::endl;
	std::cout << "isCyclePresent : " << gph.isCyclePresentColor() << std::endl;
	return 0;
}
/*
isCyclePresent : 1
isCyclePresent : 1
 */

void Graph::transposeGraph(Graph &gph) {
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		for (auto adn : adl) {
			int dest = adn.dest;
			gph.addDirectedEdge(dest, i);
		}
	}
}

// Testing code.
int main12() {
	Graph gph(4);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(0, 2);
	gph.addDirectedEdge(1, 2);
	gph.addDirectedEdge(2, 3);
	std::cout << "Graph is ::" << std::endl;
	gph.print();
	std::cout << "Transpose Graph is ::" << std::endl;
	Graph gReversed = Graph(4);
	gph.transposeGraph(gReversed);
	gReversed.print();
	return 0;
}

/*
Graph is ::
Vertex 0 is connected to : 1(cost: 1) 2(cost: 1) 
Vertex 1 is connected to : 2(cost: 1) 
Vertex 2 is connected to : 3(cost: 1) 
Vertex 3 is connected to : 

Transpose Graph is ::
Vertex 0 is connected to : 
Vertex 1 is connected to : 0(cost: 1) 
Vertex 2 is connected to : 0(cost: 1) 1(cost: 1) 
Vertex 3 is connected to : 2(cost: 1) 
 */

bool Graph::isConnectedUndirected() {
	std::vector<bool> visited(count, false);
	dfsUtil(0, visited);
	for (int i = 0; i < count; i++) {
		if (visited[i] == false) {
			return false;
		}
	}
	return true;
}

// Testing code.
int main13() {
	Graph gph(6);
	gph.addUndirectedEdge(0, 1, 1);
	gph.addUndirectedEdge(1, 2, 1);
	gph.addUndirectedEdge(3, 4, 1);
	gph.addUndirectedEdge(4, 2, 1);
	gph.addUndirectedEdge(2, 5, 1);
	//gph.addUndirectedEdge(4, 1, 1);
	std::cout << "IsConnectedUndirected : " << gph.isConnectedUndirected()
			<< std::endl;
	return 0;
}

/*
 IsConnectedUndirected : 1
 */

bool Graph::isStronglyConnected() {
	std::vector<bool> visited(count, false);
	dfsUtil(0, visited);
	for (int i = 0; i < count; i++) {
		if (visited[i] == false)
			return false;
	}

	Graph gReversed = Graph(count);
	transposeGraph(gReversed);
	for (int i = 0; i < count; i++)
		visited[i] = false;

	gReversed.dfsUtil(0, visited);

	for (int i = 0; i < count; i++)
		if (visited[i] == false)
			return false;

	return true;
}

// Testing code.
int main14() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1, 1);
	gph.addDirectedEdge(1, 2, 1);
	gph.addDirectedEdge(2, 3, 1);
	gph.addDirectedEdge(3, 0, 1);
	gph.addDirectedEdge(2, 4, 1);
	gph.addDirectedEdge(4, 2, 1);
	std::cout << "IsStronglyConnected:: " << gph.isStronglyConnected()
			<< std::endl;
	return 0;
}

/*
IsStronglyConnected:: 1
 */

void Graph::stronglyConnectedComponent() {
	std::vector<bool> visited(count, false);
	std::stack<int> stk;
	for (int i = 0; i < count; i++) {
		if (visited[i] == false) {
			dfsUtil2(i, visited, stk);
		}
	}

	for (int i = 0; i < count; i++) {
		visited[i] = false;
	}

	Graph gReversed = Graph(count);
	transposeGraph(gReversed);

	while (stk.empty() == false) {
		int index = stk.top();
		stk.pop();
		if (visited[index] == false) {
			std::stack<int> stk2;
			gReversed.dfsUtil2(index, visited, stk2);
			printStack(stk2);
		}
	}
}

// Testing code.
int main15() {
	Graph gph(7);
	gph.addDirectedEdge(0, 1);
	gph.addDirectedEdge(1, 2);
	gph.addDirectedEdge(2, 0);
	gph.addDirectedEdge(2, 3);
	gph.addDirectedEdge(3, 4);
	gph.addDirectedEdge(4, 5);
	gph.addDirectedEdge(5, 3);
	gph.addDirectedEdge(5, 6);
	gph.stronglyConnectedComponent();
	return 0;
}

/*
[ 0 2 1 ]
[ 3 5 4 ]
[ 6 ]
 */

int Graph::heightTreeParentArr(int arr[], int count) {
	int *heightArr = new int[count];
	Graph gph(count);
	int source = 0;
	for (int i = 0; i < count; i++) {
		if (arr[i] != -1)
			gph.addDirectedEdge(arr[i], i);
		else
			source = i;
	}
	std::vector<bool> visited(count, false);
	visited[source] = true;
	std::queue<int> que;
	que.push(source);
	heightArr[source] = 0;
	int maxHight = 0;
	while (que.empty() == false) {
		int curr = que.front();
		que.pop();
		int height = heightArr[curr];
		if (height > maxHight)
			maxHight = height;

		auto &adl = gph.Adj[curr];
		for (auto adn : adl) {
			if (visited[adn.dest] == false) {
				visited[adn.dest] = true;
				que.push(adn.dest);
				heightArr[adn.dest] = height + 1;
			}
		}
	}
	return maxHight;
}

int getHeight(int arr[], int height[], int index) {
	if (arr[index] == -1)
		return 0;
	else
		return getHeight(arr, height, arr[index]) + 1;
}

int Graph::heightTreeParentArr2(int arr[], int count) {
	int *height = new int[count];
	int maxHeight = -1;
	for (int i = 0; i < count; i++) {
		height[i] = getHeight(arr, height, i);
		maxHeight = std::max(maxHeight, height[i]);
	}
	return maxHeight;
}

// Testing code.
int main16() {
	int parentArray[] = { -1, 0, 1, 2, 3 };
	std::cout << "Height : " << Graph::heightTreeParentArr(parentArray, 5)
			<< std::endl;
	std::cout << "Height : " << Graph::heightTreeParentArr2(parentArray, 5)
			<< std::endl;
	return 0;
}

/*
Height : 4
Height : 4
 */

bool Graph::isConnected() {
	std::vector<bool> visited(count, false);

	// Find a vertex with non - zero degree
	// dfs traversal of graph from a vertex with non - zero degree
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		if (adl.size() > 0) {
			dfsUtil(i, visited);
			break;
		}
	}
	// Check if all non - zero degree count are visited
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		if (adl.size() > 0)
			if (visited[i] == false)
				return false;
	}
	return true;
}

void Graph::primsMST() {
	std::vector<int> previous(count, -1);
	std::vector<int> dist(count, std::numeric_limits<int>::max());
	std::vector<bool> visited(count, false);

	int source = 0;
	dist[source] = 0;
	previous[source] = source;

	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;
	Edge *node = new Edge(source, source, 0);
	queue.push(node);

	while (queue.empty() != true) {
		node = queue.top();
		queue.pop();

		source = node->dest;
		visited[source] = true;

		auto &adl = Adj[source];
		for (auto adn : adl) {
			int dest = adn.dest;
			int alt = adn.cost;
			if (dist[dest] > alt && visited[dest] == false) {
				dist[dest] = alt;
				previous[dest] = source;
				node = new Edge(source, dest, alt);
				queue.push(node);
			}
		}
	}
	// printing result.
	int total = 0;
	std::cout << "Edges are : ";
	for (int i = 0; i < count; i++) {
		if (dist[i] == std::numeric_limits<int>::max())
			std::cout << "(" << i << " is unreachable) ";
		else if (previous[i] != i)
			std::cout << "(" << previous[i] << "->" << i << " @ " << dist[i]
					<< ") ";
		total += dist[i];
	}
	std::cout << "\nTotal MST cost: " << total << std::endl;
}

// Testing code.
int main17() {
	Graph graph = Graph(9);
	graph.addUndirectedEdge(0, 1, 4);
	graph.addUndirectedEdge(0, 7, 8);
	graph.addUndirectedEdge(1, 2, 8);
	graph.addUndirectedEdge(1, 7, 11);
	graph.addUndirectedEdge(2, 3, 7);
	graph.addUndirectedEdge(2, 8, 2);
	graph.addUndirectedEdge(2, 5, 4);
	graph.addUndirectedEdge(3, 4, 9);
	graph.addUndirectedEdge(3, 5, 14);
	graph.addUndirectedEdge(4, 5, 10);
	graph.addUndirectedEdge(5, 6, 2);
	graph.addUndirectedEdge(6, 7, 1);
	graph.addUndirectedEdge(6, 8, 6);
	graph.addUndirectedEdge(7, 8, 7);

	std::cout << std::endl;
	graph.dijkstra(0);

	std::cout << std::endl;
	graph.primsMST();

	std::cout << std::endl;
	graph.kruskalMST();
	return 0;
}

/*
Shortest Paths : (0->1 @ 4) (0->1->2 @ 12) (0->1->2->3 @ 19) (0->7->6->5->4 @ 21) (0->7->6->5 @ 11) (0->7->6 @ 9) (0->7 @ 8) (0->1->2->8 @ 14) 

Edges are : (0->1 @ 4) (5->2 @ 4) (2->3 @ 7) (3->4 @ 9) (6->5 @ 2) (7->6 @ 1) (0->7 @ 8) (2->8 @ 2) 
Total MST cost: 37

Edges are : (6->7 @ 1) (5->6 @ 2) (8->2 @ 2) (2->5 @ 4) (1->0 @ 4) (3->2 @ 7) (0->7 @ 8) (4->3 @ 9)
Total MST cost: 37
*/

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

void Graph::shortestPath(int source) {	// unweighted graph
	std::vector<int> previous(count, -1);
	std::vector<int> distance(count, std::numeric_limits<int>::max());

	std::queue<int> que;
	que.push(source);
	distance[source] = 0;
	previous[source] = source;

	while (que.empty() == false) {
		int curr = que.front();
		que.pop();
		auto &adl = Adj[curr];
		for (auto adn : adl) {
			if (distance[adn.dest] == std::numeric_limits<int>::max()) {
				distance[adn.dest] = distance[curr] + 1;
				previous[adn.dest] = curr;
				que.push(adn.dest);
			}
		}
	}
	printPath(previous, distance, count, source);
}

int main18() {
	Graph gph(9);
	gph.addUndirectedEdge(0, 1);
	gph.addUndirectedEdge(0, 7);
	gph.addUndirectedEdge(1, 2);
	gph.addUndirectedEdge(1, 7);
	gph.addUndirectedEdge(2, 3);
	gph.addUndirectedEdge(2, 8);
	gph.addUndirectedEdge(2, 5);
	gph.addUndirectedEdge(3, 4);
	gph.addUndirectedEdge(3, 5);
	gph.addUndirectedEdge(4, 5);
	gph.addUndirectedEdge(5, 6);
	gph.addUndirectedEdge(6, 7);
	gph.addUndirectedEdge(6, 8);
	gph.addUndirectedEdge(7, 8);
	gph.shortestPath(0);
	return 0;
}

/*
Shortest Paths: (0->1 @ 1) (0->1->2 @ 2) (0->1->2->3 @ 3) 
(0->1->2->3->4 @ 4) (0->1->2->5 @ 3) (0->7->6 @ 2) (0->7 @ 1) (0->7->8 @ 2) 
 */

void Graph::dijkstra(int source) {
	std::vector<int> previous(count, -1);
	std::vector<int> dist(count, std::numeric_limits<int>::max()); // infinite
	std::vector<bool> visited(count, false);

	dist[source] = 0;
	previous[source] = source;
	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;
	Edge *node = new Edge(source, source, 0);
	queue.push(node);

	while (queue.empty() != true) {
		node = queue.top();
		queue.pop();
		int src = node->dest;
		visited[src] = true;

		auto &adl = Adj[src];
		for (auto adn : adl) {
			int dest = adn.dest;
			int alt = adn.cost + dist[src];
			
			if (dist[dest] > alt && visited[dest] == false) {
				dist[dest] = alt;
				previous[dest] = src;
				node = new Edge(src, dest, alt);
				queue.push(node);
			}
		}
	}

	printPath(previous, dist, count, source);
}

void Graph::bellmanFordshortestPath(int source) {
	std::vector<int> previous(count, -1);
	std::vector<int> distance(count, std::numeric_limits<int>::max());
	distance[source] = 0;
	previous[source] = source;
	// Outer loop will run (V-1) number of times.
	// Inner for loop and while loop runs combined will
	// run for Edges number of times.
	// Which make the total complexity as O(V*E).

	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count; j++) {
			auto &adl = Adj[j];
			for (auto adn : adl) {
				int newDistance = distance[j] + adn.cost;
				if (distance[adn.dest] > newDistance) {
					distance[adn.dest] = newDistance;
					previous[adn.dest] = j;
				}

			}
		}
	}
	printPath(previous, distance, count, source);
}

// Testing code.
int main19() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1, 3);
	gph.addDirectedEdge(0, 4, 2);
	gph.addDirectedEdge(1, 2, 1);
	gph.addDirectedEdge(2, 3, 1);
	gph.addDirectedEdge(4, 1, -2);
	gph.addDirectedEdge(4, 3, 1);
	std::cout << std::endl;
	gph.bellmanFordshortestPath(0);
	return 0;
}

/*
Shortest Paths : (0->4->1 @ 0) (0->4->1->2 @ 1) (0->4->1->2->3 @ 2) (0->4 @ 2) 
*/

int Graph::isEulerian() {
	// Check if all non - zero degree nodes are connected
	int odd;
	if (isConnected() == false) {
		std::cout << "graph is not Eulerian" << std::endl;
		return 0;
	} else {
		// Count odd degree
		odd = 0;
		std::vector<int> inDegree(count, 0);
		std::vector<int> outDegree(count, 0);

		for (int i = 0; i < count; i++) {
			inDegree[i] = 0;
			outDegree[i] = 0;
		}
		for (int i = 0; i < count; i++) {
			auto &adl = Adj[i];
			for (auto adn : adl) {
				outDegree[i] += 1;
				inDegree[adn.dest] += 1;
			}
		}
		for (int i = 0; i < count; i++) {
			if ((inDegree[i] + outDegree[i]) % 2 != 0) {
				odd += 1;
			}
		}
	}

	if (odd == 0) {
		std::cout << "graph is Eulerian" << std::endl;
		return 2;
	} else if (odd == 2) {
		std::cout << "graph is Semi-Eulerian" << std::endl;
		return 1;
	} else {
		std::cout << "graph is not Eulerian" << std::endl;
		return 0;
	}
}

// Testing code.
int main20() {
	Graph gph(5);
	gph.addDirectedEdge(1, 0, 1);
	gph.addDirectedEdge(0, 2, 1);
	gph.addDirectedEdge(2, 1, 1);
	gph.addDirectedEdge(0, 3, 1);
	gph.addDirectedEdge(3, 4, 1);
	gph.isEulerian();

	gph.addDirectedEdge(4, 0, 1);
	gph.isEulerian();
	return 0;
}

/*
 graph is Semi-Eulerian
 graph is Eulerian
 */

bool Graph::isStronglyConnected2() {
	std::vector<bool> visited(count, false);
	int index;
	// Find a vertex with non - zero degree
	for (index = 0; index < count; index++) {
		auto &adl = Adj[index];
		if (adl.size() > 0)
			break;
	}
	//Dfs traversal of graph from a vertex with non-zero degree
	dfsUtil(index, visited);
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[index];
		if (visited[i] == false && adl.size() > 0)
			return false;
	}

	Graph gReversed = Graph(count);
	transposeGraph(gReversed);
	for (int i = 0; i < count; i++)
		visited[i] = false;

	gReversed.dfsUtil(index, visited);

	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		if (visited[i] == false && adl.size() > 0)
			return false;
	}
	return true;
}

bool Graph::isEulerianCycle() {
	// Check if all non - zero degree count are connected
	std::vector<int> inDegree(count, 0);
	std::vector<int> outDegree(count, 0);

	if (!isStronglyConnected())
		return false;

	// Check if in degree and out degree of every vertex is same
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		for (auto adn : adl) {
			outDegree[i] += 1;
			inDegree[adn.dest] += 1;
		}
	}

	for (int i = 0; i < count; i++)
		if (inDegree[i] != outDegree[i])
			return false;

	return true;
}

// Testing code.
int main21() {
	Graph gph(5);
	gph.addDirectedEdge(0, 1, 1);
	gph.addDirectedEdge(1, 2, 1);
	gph.addDirectedEdge(2, 0, 1);
	gph.addDirectedEdge(0, 4, 1);
	gph.addDirectedEdge(4, 3, 1);
	gph.addDirectedEdge(3, 0, 1);
	std::cout << gph.isEulerianCycle() << std::endl;
	return 0;
}
/*
 1
 */

Sets::Sets(int p, int r) {
	parent = p;
	rank = r;
}

int Graph::find(std::vector<Sets*> &sets, int index) {
	int p = sets[index]->parent;
	while (p != index) {
		index = p;
		p = sets[index]->parent;
	}
	return index;
}

void Graph::union_Keyword(std::vector<Sets*> &sets, int x, int y) {
	if (sets[x]->rank < sets[y]->rank)
		sets[x]->parent = y;
	else if (sets[y]->rank < sets[x]->rank)
		sets[y]->parent = x;
	else {
		sets[x]->parent = y;
		sets[y]->rank++;
	}
}

void Graph::kruskalMST() {
	//Different subsets are created.
	std::vector<Sets*> sets(count);
	for (int i = 0; i < count; i++)
		sets[i] = new Sets(i, 0);

	// Edges are added to array and sorted.
	int E = 0;
	std::vector<Edge*> edge;
	for (int i = 0; i < count; i++) {
		auto &adl = Adj[i];
		auto len = adl.size();
		for (int j = 0; j < len; j++) {
			edge.push_back(&adl[j]); //(new Edge(adn.src, adn.dest, adn.cost));
			E++;
		}
	}
	std::sort(edge.begin(), edge.begin() + (E - 1), compare);
	int sum = 0;
	std::cout << "Edges are : ";
	for (int i = 0; i < E; i++) {
		int x = find(sets, edge[i]->src);
		int y = find(sets, edge[i]->dest);
		if (x != y) {
			std::cout << "(" << edge[i]->src << "->" << edge[i]->dest << " @ "
					<< edge[i]->cost << ") ";
			sum += edge[i]->cost;
			union_Keyword(sets, x, y);
		}
	}
	std::cout << "\nTotal MST cost: " << sum << std::endl;
}

void Graph::printPath2(std::vector<std::vector<int>> &path, int u, int v) {
	if (path[u][v] == u) {
		std::cout << u << "->" << v ;
		return;
	}
	printPath2(path, u, path[u][v]);
	std::cout << "->" << v ;
}

void Graph::printSolution(std::vector<std::vector<int>> &cost,
		std::vector<std::vector<int>> &path, int V) {
	std::cout << "Shortest Paths : ";
	for (int u = 0; u < V; u++) {
		for (int v = 0; v < V; v++) {
			if (u != v && path[u][v] != -1) {
				std::cout << "(";
				printPath2(path, u, v);
				std::cout << " @ " << cost[u][v]<< ") ";
			}
		}
	}
	std::cout << std::endl;
}

void Graph::floydWarshall() {
	int V = count;
	std::vector<std::vector<int>> dist(V, std::vector<int>(V, 99999));
	std::vector<std::vector<int>> path(V, std::vector<int>(V, 0));
	constexpr int INF = 99999;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i == j)
				path[i][j] = 0;
			else
				path[i][j] = -1;
		}
	}

	for (int i = 0; i < V; i++) {
		auto &adl = Adj[i];
		for (auto adn : adl) {
			path[adn.src][adn.dest] = adn.src;
			dist[adn.src][adn.dest] = adn.cost;
		}
	}

	for (int k = 0; k < V; k++) { // Pick intermediate vertices. 
		for (int i = 0; i < V; i++) { // Pick source vertices one by one.
			for (int j = 0; j < V; j++) { // Pick destination vertices.
				// If we have a shorter path from i to j via k.
				// then update dist[i][j] and  and path[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
			// dist[i][i] is 0 in the start.
			// If there is a better path from i to i and is better path then we have -ve cycle.                //
			if (dist[i][i] < 0) {
				std::cout << "Negative-weight cycle found." << std::endl;
				return;
			}
		}
	}
	printSolution(dist, path, V);
}

int main22() {
	Graph gph(5);
	gph.addDirectedEdge(0, 0, 0);
	gph.addDirectedEdge(1, 1, 0);
	gph.addDirectedEdge(2, 2, 0);
	gph.addDirectedEdge(3, 3, 0);

	gph.addDirectedEdge(0, 1, 5);
	gph.addDirectedEdge(0, 3, 10);
	gph.addDirectedEdge(1, 2, 3);
	gph.addDirectedEdge(2, 3, 1);
	gph.floydWarshall();
	return 0;
}

/*
Shortest Paths : (0->1 @ 5) (0->1->2 @ 8) (0->1->2->3 @ 9) (1->2 @ 3) (1->2->3 @ 4) (2->3 @ 1) 
*/

int main() {
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	main8();
	main9();
	main10();
	main11();
	main12();
	main13();
	main14();
	main15();
	main16();
	main17();
	main18();
	main19();
	main20();
	main21();
	main22();
	return 0;
}
