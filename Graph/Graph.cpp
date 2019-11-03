#include "Graph.h"

Graph::Edge::Edge(int dst, int cst = 1)
{
	destination = dst;
	cost = cst;
}

Graph::Graph(int cnt)
{
	count = cnt;
	Adj = std::vector<std::vector<Edge*>>(cnt);
}

void Graph::AddDirectedEdge(int source, int destination, int cost)
{
	Edge *edge = new Edge(destination, cost);
	Adj[source].push_back(edge);
}

void Graph::AddDirectedEdge(int source, int destination)
{
	AddDirectedEdge(source, destination, 1);
}

void Graph::AddUnDirectedEdge(int source, int destination, int cost)
{
	AddDirectedEdge(source, destination, cost);
	AddDirectedEdge(destination, source, cost);
}

void Graph::AddUnDirectedEdge(int source, int destination)
{
	AddUnDirectedEdge(source, destination, 1);
}

void Graph::Print()
{
	for (int i = 0; i < count; i++)
	{
		auto adl = Adj[i];
		std::cout << "Vertex " << i << " is connected to : ";
		for (auto adn : adl)
		{
			std::cout << adn->destination << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::dfsUtil(int index, std::vector<bool> &visited)
{
	visited[index] = true;
	auto adl = Adj[index];
	for ( auto adn : adl)
	{
	    if (visited[adn->destination] == false)
            dfsUtil(adn->destination, visited);        
	}	
}


void Graph::dfsUtil2(int index, std::vector<bool> &visited, 
	std::stack<int> &stk)
{
	visited[index] = true;
	auto adl = Adj[index];
	for ( auto adn : adl)
	{
	    if (visited[adn->destination] == false)
            dfsUtil2(adn->destination, visited, stk);        
	}	
	stk.push(index);
}

bool Graph::DFS(int source, int target)
{
	std::vector<bool> visited(count, false);
	dfsUtil(source, visited);
	return visited[target];
}

void Graph::DFSRec(int index, std::vector<bool> &visited)
{
	auto adl = Adj[index];
	for (auto adn : adl)
	{
		if (visited[adn->destination] == false)
		{
			visited[adn->destination] = true;
			DFSRec(adn->destination, visited);
		}	
	}
}

bool Graph::DFSStack(int source, int target)
{
	std::vector<bool> visited(count, false);
	int curr;
	std::stack<int> stk;

	visited[source] = true;
	stk.push(source);

	while (stk.empty() == false)
	{
		curr = stk.top();
		stk.pop();
		
		auto adl = Adj[curr];
		for (auto adn : adl)
		{
			if (visited[adn->destination] == false)
			{
				visited[adn->destination] = true;
				stk.push(adn->destination);
			}	
		}
	}

	return visited[target];
}

bool Graph::BFS(int source, int target)
{
	std::vector<bool> visited(count, false);
	int curr;
	std::queue<int> que;

	visited[source] = true;
	que.push(source);

	while (que.empty() == false)
	{
		curr = que.front();
		que.pop();
	
		auto adl = Adj[curr];
		for (auto adn : adl)
		{
			if (visited[adn->destination] == false)
			{
				visited[adn->destination] = true;
				que.push(adn->destination);
			}	
		}
	}
    return visited[target];
}


int main0()
{
	Graph* g = new Graph(9);
	g->AddUnDirectedEdge(0, 2, 1);
	g->AddUnDirectedEdge(1, 2, 5);
	g->AddUnDirectedEdge(1, 3, 7);
	g->AddUnDirectedEdge(1, 4, 9);
	g->AddUnDirectedEdge(3, 2, 2);
	g->AddUnDirectedEdge(3, 5, 4);
	g->AddUnDirectedEdge(4, 5, 6);
	g->AddUnDirectedEdge(4, 6, 3);
	g->AddUnDirectedEdge(5, 7, 1);
	g->AddUnDirectedEdge(6, 7, 7);
	g->AddUnDirectedEdge(7, 8, 17);
	g->Print();

	//g->Dijkstra(1);
	//g->Prims();
}

int main1() {
    Graph* gph = new Graph(5);
    gph->AddDirectedEdge(0, 1, 3);
    gph->AddDirectedEdge(0, 4, 2);
    gph->AddDirectedEdge(1, 2, 1);
    gph->AddDirectedEdge(2, 3, 1);
    gph->AddDirectedEdge(4, 1, -2);
    gph->AddDirectedEdge(4, 3, 1);
    gph->Print();
    std::cout << (gph->DFS(0, 2));
    std::cout << (gph->BFS(0, 2));
    std::cout << (gph->DFSStack(0, 2));
    return 0;
}

void Graph::TopologicalSort()
{
	std::stack<int> stk;
	std::vector<bool> visited(count, false);
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == false)
		{
			dfsUtil2(i, visited, stk);
		}
	}
	while (stk.empty() != true)
	{
		std::cout << stk.top() << " ";
		stk.pop();
	}
}

int main2() {
    Graph* gph = new Graph(6);
    gph->AddDirectedEdge(5, 2, 1);
    gph->AddDirectedEdge(5, 0, 1);
    gph->AddDirectedEdge(4, 0, 1);
    gph->AddDirectedEdge(4, 1, 1);
    gph->AddDirectedEdge(2, 3, 1);
    gph->AddDirectedEdge(3, 1, 1);
    gph->Print();
    gph->TopologicalSort();
	return 0;
}

bool Graph::PathExist(int source, int dest) {
	std::vector<bool> visited(count, false);
	
    dfsUtil(source, visited);
    return visited[dest];
}

int Graph::countAllPathDFS(std::vector<bool> &visited, int source, int dest) {
    if (source == dest) {
        return 1;
    }
    int count = 0;
    visited[source] = true;
    
	auto adl = Adj[source];
	for (auto adn : adl)
	{
		if (visited[adn->destination] == false)
		{
			
            count += countAllPathDFS(visited, adn->destination, dest);
		}
		visited[source] = false;
	}
    return count;
}

int Graph::CountAllPath(int src, int dest) {
	std::vector<bool> visited(count, false);

    return countAllPathDFS(visited, src, dest);
}

void Graph::printAllPathDFS(std::vector<bool> &visited, int source, int dest, std::stack<int>& previous) {
    previous.push(source);

    if (source == dest) {
        /*for (auto i : previous)
        	std::cout << i;
        */
        previous.pop();
        return;
    }
    visited[source] = true;
    
	auto adl = Adj[source];
	for (auto adn : adl)
	{
		if (visited[adn->destination] == false)
		{
            printAllPathDFS(visited, adn->destination, dest, previous);
		}	
	}

    visited[source] = false;
    previous.pop();
}

void Graph::PrintAllPath(int src, int dest) {
	std::vector<bool> visited(count, false);
	std::stack<int> previous;
	printAllPathDFS(visited, src, dest, previous);
}

int main3() {
    Graph* gph = new Graph(5);
    gph->AddDirectedEdge(0, 1, 1);
    gph->AddDirectedEdge(0, 2, 1);
    gph->AddDirectedEdge(2, 3, 1);
    gph->AddDirectedEdge(1, 3, 1);
    gph->AddDirectedEdge(3, 4, 1);
    gph->AddDirectedEdge(1, 4, 1);
    gph->Print();
    std::cout << "PathExist :: " << gph->PathExist(0, 4)<< std::endl;
    std::cout << gph->CountAllPath(0, 4);
    gph->PrintAllPath(0, 4);
    return 0;
}

    int Graph::RootVertex() {
        
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

    int main4() {
        Graph* gph = new Graph(7);
        gph->AddDirectedEdge(0, 1, 1);
        gph->AddDirectedEdge(0, 2, 1);
        gph->AddDirectedEdge(1, 3, 1);
        gph->AddDirectedEdge(4, 1, 1);
        gph->AddDirectedEdge(6, 4, 1);
        gph->AddDirectedEdge(5, 6, 1);
        gph->AddDirectedEdge(5, 2, 1);
        gph->AddDirectedEdge(6, 0, 1);
        gph->Print();
        gph->RootVertex();
        return 0;
    }


void Graph::transitiveClosureUtil(int source, int dest, std::vector<std::vector<int>> & tc) {
        tc[source][dest] = 1;

        auto adl = Adj[dest];
		for (auto adn : adl)
		{
            if (tc[source][adn->destination] == 0)
                transitiveClosureUtil(source, adn->destination, tc);
        }
    }

    void Graph::TransitiveClosure(std::vector<std::vector<int>> &tc) {
        for (int i = 0; i < count; i++) {
            transitiveClosureUtil(i, i, tc);
        }
    }




    int main5() {
        Graph* gph = new Graph(4);
        std::vector<std::vector<int>> tc(4, std::vector<int>(4, 0));
        gph->AddDirectedEdge(0, 1, 1);
        gph->AddDirectedEdge(0, 2, 1);
        gph->AddDirectedEdge(1, 2, 1);
        gph->AddDirectedEdge(2, 0, 1);
        gph->AddDirectedEdge(2, 3, 1);
        gph->AddDirectedEdge(3, 3, 1);
        gph->TransitiveClosure(tc);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << tc[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return 0;
    }


/*
* Given a directed graph, find transitive closure matrix or reach ability
* matrix vertex v is reachable form vertex u if their is a previous from u to v.
*/

    

void Graph::bfsLevelNode(int source) {
    
    std::vector<bool> visited(count, false);
    std::vector<int> level(count, 0);
    visited[source] = true;

    std::queue<int> que;
    que.push(source);
    level[source] = 0;
    std::cout << "\nNode  - Level";

    while (que.empty() == false) {
        int curr = que.front();
		que.pop();

        int depth = level[curr];
        auto adl = Adj[curr];
        std::cout << curr << " - " << depth << std::endl;
        for (auto adn : adl) {
            if (visited[adn->destination] == false) {
                visited[adn->destination] = true;
                que.push(adn->destination);
                level[adn->destination] = depth + 1;
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
            auto adl = Adj[curr];
            for (auto adn : adl) {
                if (adn->destination == dest) {
                    return depth+1;
                }
                if (visited[adn->destination] == false) {
                    visited[adn->destination] = true;
                    que.push(adn->destination);
                    level[adn->destination] = depth + 1;
                }
            }
        }
        return -1;
    }

    int main6() {
        Graph* gph = new Graph(7);
        gph->AddUnDirectedEdge(0, 1, 1);
        gph->AddUnDirectedEdge(0, 2, 1);
        gph->AddUnDirectedEdge(0, 4, 1);
        gph->AddUnDirectedEdge(1, 2, 1);
        gph->AddUnDirectedEdge(2, 5, 1);
        gph->AddUnDirectedEdge(3, 4, 1);
        gph->AddUnDirectedEdge(4, 5, 1);
        gph->AddUnDirectedEdge(4, 6, 1);
        gph->Print();
        gph->bfsLevelNode(1);
        std::cout << gph->bfsDistance(1, 6);
        return 0;
    }


    bool Graph::isCyclePresentUndirectedDFS(int index, int parentIndex, std::vector<bool>& visited) {
        visited[index] = true;
        int dest;
        auto adl = Adj[index];
        for (auto adn : adl) {
            dest = adn->destination;
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

    int main7() {
        Graph* gph = new Graph(6);
        gph->AddUnDirectedEdge(0, 1, 1);
        gph->AddUnDirectedEdge(1, 2, 1);
        gph->AddUnDirectedEdge(3, 4, 1);
        gph->AddUnDirectedEdge(4, 2, 1);
        gph->AddUnDirectedEdge(2, 5, 1);
        //gph->AddUnDirectedEdge(4, 1, 1);
        std::cout << gph->isCyclePresentUndirected() << std::endl;
    	return 0;
    }


/*
 * Given a directed graph find if there is a cycle in it.
 */
    bool Graph::isCyclePresentDFS(int index, std::vector<bool>& visited, std::vector<int>& marked) {
        visited[index] = true;
        marked[index] = 1;
        auto adl = Adj[index];
        for (auto adn : adl) {
            int dest = adn->destination;
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

    bool Graph::isCyclePresentDFSColor(int index, std::vector<int>& visited) {
        visited[index] = 1; // 1 = grey
        int dest;
        auto adl = Adj[index];
        for (auto adn : adl) {
            dest = adn->destination;
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

    int main8() {
        Graph* gph = new Graph(5);
        gph->AddDirectedEdge(0, 1, 1);
        gph->AddDirectedEdge(0, 2, 1);
        gph->AddDirectedEdge(2, 3, 1);
        gph->AddDirectedEdge(1, 3, 1);
        gph->AddDirectedEdge(3, 4, 1);
        //gph->AddDirectedEdge(4, 1, 1);
        std::cout << gph->isCyclePresentColor() << std::endl;
        return 0;
    }


    Graph* Graph::transposeGraph() {
        
        Graph* g = new Graph(count);
        for (int i = 0; i < count; i++) {
            auto adl = Adj[i];
            for (auto adn : adl) {
                int dest = adn->destination;
                g->AddDirectedEdge(dest, i);
            }
        }
        return g;
    }

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

    /*
     * Kosaraju Algorithm
     * 
     * Kosaraju’s Algorithm to find strongly connected directed graph based on DFS :
     * 1) Create a visited array of size V, and Initialize all count in visited
     * array as 0. 2) Choose any vertex and perform a DFS traversal of graph. For
     * all visited count mark them visited as 1. 3) If DFS traversal does not mark
     * all count as 1, then return 0. 4) Find transpose or reverse of graph 5)
     * Repeat step 1, 2 and 3 for the reversed graph. 6) If DFS traversal mark all
     * the count as 1, then return 1.
     */
    bool Graph::isStronglyConnected() {
        
        std::vector<bool> visited(count, false);


        dfsUtil(0, visited);
        for (int i = 0; i < count; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        Graph* gReversed = transposeGraph();
        for (int i = 0; i < count; i++) {
            visited[i] = false;
        }
        gReversed->dfsUtil(0, visited);
        for (int i = 0; i < count; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }

    int main9() {
        Graph* gph = new Graph(5);
        gph->AddDirectedEdge(0, 1, 1);
        gph->AddDirectedEdge(1, 2, 1);
        gph->AddDirectedEdge(2, 3, 1);
        gph->AddDirectedEdge(3, 0, 1);
        gph->AddDirectedEdge(2, 4, 1);
        gph->AddDirectedEdge(4, 2, 1);
        std::cout << " IsStronglyConnected:: " << gph->isStronglyConnected()<< std::endl;
    	return 0;
    }

    void PrintStack(std::stack<int> stk){
    	if(stk.empty()){
    		std::cout << std::endl;
    		return;
    	}

    	int curr = stk.top();
    	stk.pop();
	   	std::cout << curr << " ";
    	PrintStack(stk);
    }

void Graph::stronglyConnectedComponent() {
    
    std::vector<bool> visited(count, false);

    std::stack<int> stk;;
    for (int i = 0; i < count; i++) {
        if (visited[i] == false) {
            dfsUtil2(i, visited, stk);
        }
    }
    Graph* gReversed = transposeGraph();
    for (int i = 0; i < count; i++) {
        visited[i] = false;
    }

    std::stack<int> stk2;
    while (stk.empty() == false) {
        int index = stk.top(); 
        stk.pop();
        if (visited[index] == false) {
        	std::stack<int> temp;
            stk2.swap(temp);
            gReversed->dfsUtil2(index, visited, stk2);
            PrintStack(stk2);
        }
    }
}

int main10() {
    Graph* gph = new Graph(7);
    gph->AddDirectedEdge(0, 1, 1);
    gph->AddDirectedEdge(1, 2, 1);
    gph->AddDirectedEdge(2, 0, 1);
    gph->AddDirectedEdge(2, 3, 1);
    gph->AddDirectedEdge(3, 4, 1);
    gph->AddDirectedEdge(4, 5, 1);
    gph->AddDirectedEdge(5, 3, 1);
    gph->AddDirectedEdge(5, 6, 1);
    gph->stronglyConnectedComponent();
    return 0;
}

int Graph::heightTreeParentArr(int arr[], int count) {
    int* heightArr = new int[count];
    Graph* gph = new Graph(count);
    int source = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] != -1) {
            gph->AddDirectedEdge(arr[i], i);
        } else {
            source = i;
        }
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
        if (height > maxHight) {
            maxHight = height;
        }
        auto adl = gph->Adj[curr];
        for (auto adn : adl) {
            if (visited[adn->destination] == false) {
                visited[adn->destination] = true;
                que.push(adn->destination);
                heightArr[adn->destination] = height + 1;
            }
        }
    }
    return maxHight;
}

int getHeight(int arr[], int height[], int index) {
    if (arr[index] == -1) {
        return 0;
    } else {
        return getHeight(arr, height, arr[index]) + 1;
    }
}

int heightTreeParentArr2(int arr[], int count) {
    int* height = new int[count];
    int maxHeight = -1;
    for (int i = 0; i < count; i++) {
        height[i] = getHeight(arr, height, i);
        maxHeight = std::max(maxHeight, height[i]);
    }
    return maxHeight;
}

int main11() {
    int parentArray[] = { -1, 0, 1, 2, 3 };
	std::cout << Graph::heightTreeParentArr(parentArray, 5) << std::endl;
    std::cout << heightTreeParentArr2(parentArray, 5) << std::endl;
    return 0;
}


bool Graph::isConnected() {
    
    std::vector<bool> visited(count, false);

    // Find a vertex with non - zero degree
    // DFS traversal of graph from a vertex with non - zero degree
    
    for (int i = 0; i < count; i++) {
        auto adl = Adj[i];
        if (adl.size() > 0) {
            dfsUtil(i, visited);
            break;
        }
    }
    // Check if all non - zero degree count are visited
    for (int i = 0; i < count; i++) {
        auto adl = Adj[i];
        if (adl.size() > 0)
            if (visited[i] == false)
                return false;
    }
    return true;
}

/*
 * The function returns one of the following values Return 0 if graph is not
 * Eulerian Return 1 if graph has an Euler previous (Semi-Eulerian) Return 2 if
 * graph has an Euler Circuit (Eulerian)
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
        int* inDegree = new int[count];
        int* outDegree = new int[count];

        for (int i = 0; i < count; i++) {
            auto adl = Adj[i];
            for (auto adn : adl) {
                outDegree[i] += 1;
                inDegree[adn->destination] += 1;
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

int main12() {
    Graph* gph = new Graph(5);
    gph->AddDirectedEdge(1, 0, 1);
    gph->AddDirectedEdge(0, 2, 1);
    gph->AddDirectedEdge(2, 1, 1);
    gph->AddDirectedEdge(0, 3, 1);
    gph->AddDirectedEdge(3, 4, 1);
    std::cout << gph->isEulerian() << std::endl;
    return 0;
}

bool Graph::isStronglyConnected2() {
    
    std::vector<bool> visited(count, false);
    int index;
    // Find a vertex with non - zero degree
    for (index = 0; index < count; index++) {
        auto adl = Adj[index];
        if (adl.size() > 0)
            break;
    }
    // DFS traversal of graph from a vertex with non - zero degree
    dfsUtil(index, visited);
    for (int i = 0; i < count; i++) {
        auto adl = Adj[index];
        if (visited[i] == false && adl.size() > 0)
            return false;
    }

    Graph* gReversed = transposeGraph();
    for (int i = 0; i < count; i++)
        visited[i] = false;

    gReversed->dfsUtil(index, visited);

    for (int i = 0; i < count; i++) {
        auto adl = Adj[i];
        if (visited[i] == false && adl.size() > 0)
            return false;
    }
    return true;
}

bool Graph::isEulerianCycle() {
    // Check if all non - zero degree count are connected
    
std::vector<int> inDegree(count, 0);
std::vector<int> outDegree(count, 0);

    if (!isStronglyConnected2())
        return false;

    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < count; i++) {
        auto adl = Adj[i];
        for (auto adn : adl) {
            outDegree[i] += 1;
            inDegree[adn->destination] += 1;
        }
    }
    for (int i = 0; i < count; i++)
        if (inDegree[i] != outDegree[i])
            return false;
    return true;
}

int main13() {
    Graph* gph = new Graph(5);
    gph->AddDirectedEdge(0, 1, 1);
    gph->AddDirectedEdge(1, 2, 1);
    gph->AddDirectedEdge(2, 0, 1);
    gph->AddDirectedEdge(0, 4, 1);
    gph->AddDirectedEdge(4, 3, 1);
//    gph->AddDirectedEdge(3, 0, 1);
    std::cout << gph->isEulerianCycle() << std::endl;
    return 0;
}



bool Graph::EdgeComparator::operator()(Edge *x, Edge *y)
{
	if (x->cost <= y->cost)
	{
		return false;
	}
	return true;
}

void Graph::Prims() {
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;
    
    int source = 1;
    dist[source] = 0;
    previous[source] = -1;
 	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

	Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true) {
        node = queue.top();
        queue.pop();

        visited[source] = true;
        source = node->destination;
        auto adl = Adj[source];
        for (auto adn : adl) {
            int dest = adn->destination;
            int alt = adn->cost;
            if (dist[dest] > alt && visited[dest] == false) {
                dist[dest] = alt;
                previous[dest] = source;
                node = new Edge(dest, alt);
                queue.push(node);
            }
        }
    }
    // printing result.
    
    for (int i = 0; i < count; i++) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable"<< std::endl;
        } else {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i]<< std::endl;

        }
    }
}

int main14() {
    Graph* gph = new Graph(9);
    gph->AddUnDirectedEdge(0, 1, 4);
    gph->AddUnDirectedEdge(0, 7, 8);
    gph->AddUnDirectedEdge(1, 2, 8);
    gph->AddUnDirectedEdge(1, 7, 11);
    gph->AddUnDirectedEdge(2, 3, 7);
    gph->AddUnDirectedEdge(2, 8, 2);
    gph->AddUnDirectedEdge(2, 5, 4);
    gph->AddUnDirectedEdge(3, 4, 9);
    gph->AddUnDirectedEdge(3, 5, 14);
    gph->AddUnDirectedEdge(4, 5, 10);
    gph->AddUnDirectedEdge(5, 6, 2);
    gph->AddUnDirectedEdge(6, 7, 1);
    gph->AddUnDirectedEdge(6, 8, 6);
    gph->AddUnDirectedEdge(7, 8, 7);
    gph->Print();
    std::cout << std::endl;
    gph->Prims();
    std::cout << std::endl;
 //   gph->dijkstra(0);
    return 0;
}


void Graph::ShortestPath(int source)// unweighted graph
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> distance(count, -1) ;; // infinite


    std::queue<int> que;
    que.push(source);
    distance[source] = 0;
    while (que.empty() == false) {
        int curr = que.front();
        que.pop();
        auto adl = Adj[curr];
        for (auto adn : adl) {
            if (distance[adn->destination] == -1) {
                distance[adn->destination] = distance[curr] + 1;
                previous[adn->destination] = curr;
                que.push(adn->destination);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        std::cout << previous[i] << " to " << i << " weight " << distance[i]<<std::endl;
    }
}

int main15() {
    Graph* gph = new Graph(9);
    gph->AddUnDirectedEdge(0, 2, 1);
    gph->AddUnDirectedEdge(1, 2, 5);
    gph->AddUnDirectedEdge(1, 3, 7);
    gph->AddUnDirectedEdge(1, 4, 9);
    gph->AddUnDirectedEdge(3, 2, 2);
    gph->AddUnDirectedEdge(3, 5, 4);
    gph->AddUnDirectedEdge(4, 5, 6);
    gph->AddUnDirectedEdge(4, 6, 3);
    gph->AddUnDirectedEdge(5, 7, 1);
    gph->AddUnDirectedEdge(6, 7, 7);
    gph->AddUnDirectedEdge(7, 8, 17);
    //gph->bellmanFordShortestPath(1);
    gph->Dijkstra(1);
    //gph->Prims();
    std::cout << "isConnectedUndirected :: " << gph->isConnectedUndirected() << std::endl;
}

void Graph::Dijkstra(int source) {
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;// infinite
    std::vector<bool> visited(count, false) ;

    dist[source] = 0;
    previous[source] = -1;
 	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

	Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true) {
        node = queue.top();
        queue.pop();

        visited[source] = true;
        source = node->destination;
        auto adl = Adj[source];
        for (auto adn : adl) {
            int dest = adn->destination;
            int alt = adn->cost + dist[source];
            if (dist[dest] > alt && visited[dest] == false) {
                dist[dest] = alt;
                previous[dest] = source;
                node = new Edge(dest, alt);
                queue.push(node);
            }
        }
    }
    // printing result.
    
    for (int i = 0; i < count; i++) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable"<< std::endl;
        } else {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i]<< std::endl;

        }
    }
}


void Graph::BellmanFordShortestPath(int source) {
    
    std::vector<int> previous(count, -1) ;
    std::vector<int> distance(count, std::numeric_limits<int>::max()) ;

    distance[source] = 0;
    // Outer loop will run (V-1) number of times.
    // Inner for loop and while loop runs combined will
    // run for Edges number of times.
    // Which make the total complexity as O(V*E)

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count; j++) {
            auto adl = Adj[j];
            for (auto adn : adl) {
                int newDistance = distance[j] + adn->cost;
                if (distance[adn->destination] > newDistance) {
                    distance[adn->destination] = newDistance;
                    previous[adn->destination] = j;
                }

            }
        }
    }
    for (int i = 0; i < count; i++) {
        std::cout << previous[i] << " to " << i << " weight " << distance[i] << std::endl;
    }
}

int main() {
    Graph* gph = new Graph(5);
    gph->AddDirectedEdge(0, 1, 3);
    gph->AddDirectedEdge(0, 4, 2);
    gph->AddDirectedEdge(1, 2, 1);
    gph->AddDirectedEdge(2, 3, 1);
    gph->AddDirectedEdge(4, 1, -2);
    gph->AddDirectedEdge(4, 3, 1);
    gph->Print();
    std::cout << std::endl;
    gph->BellmanFordShortestPath(0);
}

int Graph::BestFirstSearchPQ(int source, int dest) {
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;


    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> pq;

    dist[source] = 0;
    previous[source] = -1;
    Edge* node = new Edge(source, 0);
    pq.push(node);

    while (pq.empty() != true) {
        node = pq.top();
        pq.pop();

        source = node->destination;
        if (source == dest) {
            return node->cost;
        }
        visited[source] = true;

        auto adl = Adj[source];
        for (auto adn : adl) {
            int curr = adn->destination;
            int cost = adn->cost;
            int alt = cost + dist[source];
            if (dist[curr] > alt && visited[curr] == false) {
                dist[curr] = alt;
                previous[curr] = source;
                node = new Edge(curr, alt);
                pq.push(node);
            }
        }
    }
    return -1;
}
