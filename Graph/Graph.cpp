#include "Graph.h"

Graph::Edge::Edge(int dst, int cst = 1)
{
    destination = dst;
    cost = cst;
}

Graph::Graph(int cnt)
{
    count = cnt;
    Adj = std::vector<std::vector<Edge>>(cnt);
}

void Graph::addDirectedEdge(int source, int destination, int cost)
{
    Adj[source].push_back(Edge(destination, cost));
}

void Graph::addDirectedEdge(int source, int destination)
{
    addDirectedEdge(source, destination, 1);
}

void Graph::addUndirectedEdge(int source, int destination, int cost)
{
    addDirectedEdge(source, destination, cost);
    addDirectedEdge(destination, source, cost);
}

void Graph::addUndirectedEdge(int source, int destination)
{
    addUndirectedEdge(source, destination, 1);
}

void Graph::print()
{
    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        std::cout << "Vertex " << i << " is connected to : ";
        for (auto adn : adl)
        {
            std::cout << adn.destination << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::dfsUtil(int index, std::vector<bool> &visited)
{
    visited[index] = true;
    auto& adl = Adj[index];
    for ( auto adn : adl)
    {
        if (visited[adn.destination] == false)
            dfsUtil(adn.destination, visited);
    }
}

bool Graph::dfs(int source, int target)
{
    std::vector<bool> visited(count, false);
    dfsUtil(source, visited);
    return visited[target];
}

bool Graph::dfsStack(int source, int target)
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

        auto& adl = Adj[curr];
        for (auto adn : adl)
        {
            if (visited[adn.destination] == false)
            {
                visited[adn.destination] = true;
                stk.push(adn.destination);
            }
        }
    }

    return visited[target];
}

bool Graph::bfs(int source, int target)
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

        auto& adl = Adj[curr];
        for (auto adn : adl)
        {
            if (visited[adn.destination] == false)
            {
                visited[adn.destination] = true;
                que.push(adn.destination);
            }
        }
    }
    return visited[target];
}


int main1()
{
    Graph gph = Graph(4);
    gph.addUndirectedEdge(0, 1, 1);
    gph.addUndirectedEdge(0, 2, 1);
    gph.addUndirectedEdge(1, 2, 1);
    gph.addUndirectedEdge(2, 3, 1);
    gph.print();
    return 0;
}

/*
Vertex 0 is connected to : 1 2
Vertex 1 is connected to : 0 2
Vertex 2 is connected to : 0 1 3
Vertex 3 is connected to : 2
*/

int main2()
{
    Graph gph = Graph(8);
    gph.addUndirectedEdge(0, 3, 1);
    gph.addUndirectedEdge(0, 2, 1);
    gph.addUndirectedEdge(0, 1, 1);
    gph.addUndirectedEdge(1, 4, 1);
    gph.addUndirectedEdge(2, 5, 1);
    gph.addUndirectedEdge(3, 6, 1);
    gph.addUndirectedEdge(6, 7, 1);
    gph.addUndirectedEdge(5, 7, 1);
    gph.addUndirectedEdge(4, 7, 1);

    std::cout << "Path between 0 & 6 : " << gph.dfs(0, 2)<< std::endl;
    std::cout << "Path between 0 & 6 : " << gph.bfs(0, 2)<< std::endl;
    std::cout << "Path between 0 & 6 : " << gph.dfsStack(0, 2)<< std::endl;
    return 0;
}

/*
Path between 0 & 6 : 1
Path between 0 & 6 : 1
Path between 0 & 6 : 1
*/

void Graph::dfsUtil2(int index, std::vector<bool> &visited, std::stack<int> &stk)
{
    visited[index] = true;
    auto& adl = Adj[index];
    for ( auto adn : adl)
    {
        if (visited[adn.destination] == false)
            dfsUtil(adn.destination, visited);
    }
    stk.push(index);
}

void Graph::topologicalSort()
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

    std::printf("Topological order of given graph is : ");
    while (stk.empty() != true)
    {
        std::cout << stk.top() << " ";
        stk.pop();
    }
}

int main3()
{
    Graph gph = Graph(6);
    gph.addDirectedEdge(5, 2, 1);
    gph.addDirectedEdge(5, 0, 1);
    gph.addDirectedEdge(4, 0, 1);
    gph.addDirectedEdge(4, 1, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(3, 1, 1);
    gph.topologicalSort();
    return 0;
}

/*
Topological order of given graph is : 5 4 2 3 1 0
*/

bool Graph::pathExist(int source, int dest)
{
    std::vector<bool> visited(count, false);

    dfsUtil(source, visited);
    return visited[dest];
}

int main4()
{
    Graph gph = Graph(5);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(1, 3, 1);
    gph.addDirectedEdge(3, 4, 1);
    gph.addDirectedEdge(1, 4, 1);
    std::cout << "PathExist :: " << gph.pathExist(0, 4) << std::endl;
    return 0;
}

/*
PathExist :: 1
*/

int Graph::countAllPathdfs(std::vector<bool> &visited, int source, int dest)
{
    if (source == dest)
    {
        return 1;
    }
    int count = 0;
    visited[source] = true;

    auto& adl = Adj[source];
    for (auto adn : adl)
    {
        if (visited[adn.destination] == false)
        {

            count += countAllPathdfs(visited, adn.destination, dest);
        }
        visited[source] = false;
    }
    return count;
}

int Graph::countAllPath(int src, int dest)
{
    std::vector<bool> visited(count, false);
    return countAllPathdfs(visited, src, dest);
}

int main5()
{
    Graph gph = Graph(5);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(1, 3, 1);
    gph.addDirectedEdge(3, 4, 1);
    gph.addDirectedEdge(1, 4, 1);
    std::cout << "Path Count :: " << gph.countAllPath(0, 4) << std::endl;
    return 0;
}

/*
Path Count :: 3
*/

void printStack(std::stack<int>& stk)
{
    if(stk.empty() == 1)
        return;
    int temp = stk.top();
    stk.pop();
    std::cout << temp << " ";
    printStack(stk);
    stk.push(temp);
}

void Graph::printAllPathdfs(std::vector<bool> &visited, int source, int dest, std::stack<int>& path)
{
    path.push(source);

    if (source == dest)
    {
        printStack(path);
        std::cout << std::endl;
        path.pop();
        return;
    }
    visited[source] = true;

    auto& adl = Adj[source];
    for (auto adn : adl)
    {
        if (visited[adn.destination] == false)
        {
            printAllPathdfs(visited, adn.destination, dest, path);
        }
    }

    visited[source] = false;
    path.pop();
}

void Graph::printAllPath(int src, int dest)
{
    std::vector<bool> visited(count, false);
    std::stack<int> path;
    printAllPathdfs(visited, src, dest, path);
}

int main6()
{
    Graph gph = Graph(5);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(1, 3, 1);
    gph.addDirectedEdge(3, 4, 1);
    gph.addDirectedEdge(1, 4, 1);
    gph.printAllPath(0, 4);
    return 0;
}

/*
4 3 1 0
4 1 0
4 3 2 0
*/

int Graph::rootVertex()
{
    std::vector<bool> visited(count, false);
    int retVal = -1;
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == false)
        {
            dfsUtil(i, visited);
            retVal = i;
        }
    }
    std::cout << "Root vertex is :: " << retVal << std::endl;
    return retVal;
}

int main7()
{
    Graph gph = Graph(7);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(1, 3, 1);
    gph.addDirectedEdge(4, 1, 1);
    gph.addDirectedEdge(6, 4, 1);
    gph.addDirectedEdge(5, 6, 1);
    gph.addDirectedEdge(5, 2, 1);
    gph.addDirectedEdge(6, 0, 1);
    gph.rootVertex();
    return 0;
}

/*
Root vertex is :: 5
*/

void Graph::transitiveClosureUtil(int source, int dest, std::vector<std::vector<int>> & tc)
{
    tc[source][dest] = 1;
    auto& adl = Adj[dest];
    for (auto adn : adl)
    {
        if (tc[source][adn.destination] == 0)
            transitiveClosureUtil(source, adn.destination, tc);
    }
}

void Graph::transitiveClosure(std::vector<std::vector<int>> &tc)
{
    for (int i = 0; i < count; i++)
        transitiveClosureUtil(i, i, tc);
}

int main8()
{
    Graph gph = Graph(4);
    std::vector<std::vector<int>> tc(4, std::vector<int>(4, 0));
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(1, 2, 1);
    gph.addDirectedEdge(2, 0, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(3, 3, 1);
    gph.transitiveClosure(tc);
    for (int i = 0; i < 4; i++)
    {
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

/*
* Given a directed graph, find transitive closure matrix or reach ability
* matrix vertex v is reachable form vertex u if their is a previous from u to v.
*/
void Graph::bfsLevelNode(int source)
{
    std::vector<bool> visited(count, false);
    std::vector<int> level(count, 0);
    visited[source] = true;

    std::queue<int> que;
    que.push(source);
    level[source] = 0;
    std::cout << "Node  - Level" << std::endl;

    while (que.empty() == false)
    {
        int curr = que.front();
        que.pop();

        int depth = level[curr];
        auto& adl = Adj[curr];
        std::cout << curr << " - " << depth << std::endl;
        for (auto adn : adl)
        {
            if (visited[adn.destination] == false)
            {
                visited[adn.destination] = true;
                que.push(adn.destination);
                level[adn.destination] = depth + 1;
            }
        }
    }
}

int Graph::bfsDistance(int source, int dest)
{

    std::vector<bool> visited(count, false);
    std::queue<int> que;
    que.push(source);
    visited[source] = true;
    std::vector<int> level(count, 0);
    level[source] = 0;

    while (que.empty() == false)
    {
        int curr = que.front();
        que.pop();
        int depth = level[curr];
        auto& adl = Adj[curr];
        for (auto adn : adl)
        {
            if (adn.destination == dest)
                return depth+1;
            
            if (visited[adn.destination] == false)
            {
                visited[adn.destination] = true;
                que.push(adn.destination);
                level[adn.destination] = depth + 1;
            }
        }
    }
    return -1;
}

int main9()
{
    Graph gph = Graph(7);
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

bool Graph::isCyclePresentUndirectedDFS(int index, int parentIndex, std::vector<bool>& visited)
{
    visited[index] = true;
    int dest;
    auto& adl = Adj[index];
    for (auto adn : adl)
    {
        dest = adn.destination;
        if (visited[dest] == false)
        {
            if (isCyclePresentUndirectedDFS(dest, index, visited))
                return true;
        }
        else if (parentIndex != dest)
            return true;
    }
    return false;
}

bool Graph::isCyclePresentUndirected()
{
    std::vector<bool> visited(count, false);
    for (int i = 0; i < count; i++)
        if (visited[i] == false)
            if (isCyclePresentUndirectedDFS(i, -1, visited))
                return true;
    return false;
}

int main10()
{
    Graph gph = Graph(6);
    gph.addUndirectedEdge(0, 1, 1);
    gph.addUndirectedEdge(1, 2, 1);
    gph.addUndirectedEdge(3, 4, 1);
    gph.addUndirectedEdge(4, 2, 1);
    gph.addUndirectedEdge(2, 5, 1);
    //gph.addUndirectedEdge(4, 1, 1);
    //gph.addUndirectedEdge(3, 5, 1);
    std::cout << gph.isCyclePresentUndirected() << std::endl;
    return 0;
}

/*
0
*/


/*
 * Given a directed graph find if there is a cycle in it.
 */
bool Graph::isCyclePresentDFS(int index, std::vector<bool>& visited, std::vector<int>& marked)
{
    visited[index] = true;
    marked[index] = 1;
    auto& adl = Adj[index];
    for (auto adn : adl)
    {
        int dest = adn.destination;
        if (marked[dest] == 1)
            return true;

        if (visited[dest] == false)
            if (isCyclePresentDFS(dest, visited, marked))
                return true;
    }
    marked[index] = 0;
    return false;
}

bool Graph::isCyclePresent()
{

    std::vector<bool> visited(count, false);
    std::vector<int> marked(count, false);
    for (int index = 0; index < count; index++)
    {
        if (visited[index] == false)
            if (isCyclePresentDFS(index, visited, marked))
                return true;
    }
    return false;
}

bool Graph::isCyclePresentDFSColor(int index, std::vector<int>& visited)
{
    visited[index] = 1; // 1 = grey
    int dest;
    auto& adl = Adj[index];
    for (auto adn : adl)
    {
        dest = adn.destination;
        if (visited[dest] == 1) // "Grey":
            return true;

        if (visited[dest] == 0) // "White":
            if (isCyclePresentDFSColor(dest, visited))
                return true;
    }
    visited[index] = 2; // "Black"
    return false;
}

bool Graph::isCyclePresentColor()
{
    std::vector<int> visited(count, 0);
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == 0) // "White"
            if (isCyclePresentDFSColor(i, visited))
                return true;
    }
    return false;
}

int main11()
{
    Graph gph = Graph(5);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(1, 3, 1);
    gph.addDirectedEdge(3, 4, 1);
    gph.addDirectedEdge(4, 1, 1);
    std::cout << gph.isCyclePresent() << std::endl;
    std::cout << gph.isCyclePresentColor() << std::endl;
    return 0;
}
/*
1
1
*/

void Graph::transposeGraph(Graph& gph)
{
    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        for (auto adn : adl)
        {
            int dest = adn.destination;
            gph.addDirectedEdge(dest, i);
        }
    }
}

int main12()
{
    Graph gph = Graph(4);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(0, 2, 1);
    gph.addDirectedEdge(1, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
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
Vertex 0 is connected to : 1 2 
Vertex 1 is connected to : 2 
Vertex 2 is connected to : 3 
Vertex 3 is connected to : 
Transpose Graph is ::
Vertex 0 is connected to : 
Vertex 1 is connected to : 0 
Vertex 2 is connected to : 0 1 
Vertex 3 is connected to : 2 
*/

bool Graph::isConnectedUndirected()
{
    std::vector<bool> visited(count, false);
    dfsUtil(0, visited);
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

int main100()
{
    Graph gph = Graph(6);
    gph.addUndirectedEdge(0, 1, 1);
    gph.addUndirectedEdge(1, 2, 1);
    gph.addUndirectedEdge(3, 4, 1);
    gph.addUndirectedEdge(4, 2, 1);
    gph.addUndirectedEdge(2, 5, 1);
    //gph.addUndirectedEdge(4, 1, 1);
    //gph.addUndirectedEdge(3, 5, 1);
    std::cout << "IsConnectedUndirected : " << gph.isConnectedUndirected() << std::endl;

    return 0;
}

/*
IsConnectedUndirected : 1
*/

/*
 * Kosaraju Algorithm
 *
 * Kosaraju’s Algorithm to find strongly connected directed graph based on dfs :
 * 1) Create a visited array of size V, and Initialize all count in visited
 * array as 0. 2) Choose any vertex and perform a dfs traversal of graph. For
 * all visited count mark them visited as 1. 3) If dfs traversal does not mark
 * all count as 1, then return 0. 4) Find transpose or reverse of graph 5)
 * Repeat step 1, 2 and 3 for the reversed graph. 6) If dfs traversal mark all
 * the count as 1, then return 1.
 */
bool Graph::isStronglyConnected()
{
    std::vector<bool> visited(count, false);
    dfsUtil(0, visited);
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    Graph gReversed = Graph(count);
    transposeGraph(gReversed);
    for (int i = 0; i < count; i++)
    {
        visited[i] = false;
    }
    gReversed.dfsUtil(0, visited);
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}


int main13()
{
    Graph gph = Graph(5);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(1, 2, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(3, 0, 1);
    gph.addDirectedEdge(2, 4, 1);
    gph.addDirectedEdge(4, 2, 1);
    std::cout << " IsStronglyConnected:: " << gph.isStronglyConnected()<< std::endl;
    return 0;
}

/*
IsStronglyConnected:: 1
*/

void Graph::stronglyConnectedComponent()
{
    std::vector<bool> visited(count, false);
    std::stack<int> stk;;
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == false)
        {
            dfsUtil2(i, visited, stk);
        }
    }
    Graph gReversed = Graph(count);
    transposeGraph(gReversed);
    for (int i = 0; i < count; i++)
    {
        visited[i] = false;
    }

    std::stack<int> stk2;
    while (stk.empty() == false)
    {
        int index = stk.top();
        stk.pop();
        if (visited[index] == false)
        {
            std::stack<int> temp;
            stk2.swap(temp);
            gReversed.dfsUtil2(index, visited, stk2);
            printStack(stk2);
        }
    }
}

int main14()
{
    Graph gph = Graph(7);
    gph.addDirectedEdge(0, 1, 1);
    gph.addDirectedEdge(1, 2, 1);
    gph.addDirectedEdge(2, 0, 1);
    gph.addDirectedEdge(2, 3, 1);
    gph.addDirectedEdge(3, 4, 1);
    gph.addDirectedEdge(4, 5, 1);
    gph.addDirectedEdge(5, 3, 1);
    gph.addDirectedEdge(5, 6, 1);
    gph.stronglyConnectedComponent();
    return 0;
}

/*
0 2 1
3 5 4
6
*/

int Graph::heightTreeParentArr(int arr[], int count)
{
    int* heightArr = new int[count];
    Graph gph = Graph(count);
    int source = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] != -1)
        {
            gph.addDirectedEdge(arr[i], i);
        }
        else
        {
            source = i;
        }
    }
    std::vector<bool> visited(count, false);
    visited[source] = true;
    std::queue<int> que;
    que.push(source);
    heightArr[source] = 0;
    int maxHight = 0;
    while (que.empty() == false)
    {
        int curr = que.front();
        que.pop();
        int height = heightArr[curr];
        if (height > maxHight)
        {
            maxHight = height;
        }
        auto& adl = gph.Adj[curr];
        for (auto adn : adl)
        {
            if (visited[adn.destination] == false)
            {
                visited[adn.destination] = true;
                que.push(adn.destination);
                heightArr[adn.destination] = height + 1;
            }
        }
    }
    return maxHight;
}

int getHeight(int arr[], int height[], int index)
{
    if (arr[index] == -1)
    {
        return 0;
    }
    else
    {
        return getHeight(arr, height, arr[index]) + 1;
    }
}

int heightTreeParentArr2(int arr[], int count)
{
    int* height = new int[count];
    int maxHeight = -1;
    for (int i = 0; i < count; i++)
    {
        height[i] = getHeight(arr, height, i);
        maxHeight = std::max(maxHeight, height[i]);
    }
    return maxHeight;
}

int main15()
{
    int parentArray[] = { -1, 0, 1, 2, 3 };
    std::cout << Graph::heightTreeParentArr(parentArray, 5) << std::endl;
    std::cout << heightTreeParentArr2(parentArray, 5) << std::endl;
    return 0;
}
/*
4
4
*/

bool Graph::isConnected()
{

    std::vector<bool> visited(count, false);

    // Find a vertex with non - zero degree
    // dfs traversal of graph from a vertex with non - zero degree

    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        if (adl.size() > 0)
        {
            dfsUtil(i, visited);
            break;
        }
    }
    // Check if all non - zero degree count are visited
    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        if (adl.size() > 0)
            if (visited[i] == false)
                return false;
    }
    return true;
}

bool Graph::EdgeComparator::operator()(Edge *x, Edge *y)
{
    if (x->cost <= y->cost)
    {
        return false;
    }
    return true;
}

void Graph::prims()
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;

    int source = 1;
    dist[source] = 0;
    previous[source] = -1;
    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

    Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true)
    {
        node = queue.top();
        queue.pop();

        visited[source] = true;
        source = node->destination;
        auto& adl = Adj[source];
        for (auto adn : adl)
        {
            int dest = adn.destination;
            int alt = adn.cost;
            if (dist[dest] > alt && visited[dest] == false)
            {
                dist[dest] = alt;
                previous[dest] = source;
                node = new Edge(dest, alt);
                queue.push(node);
            }
        }
    }
    // printing result.

    for (int i = 0; i < count; i++)
    {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable"<< std::endl;
        else
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i]<< std::endl;
    }
}

int main16()
{
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
    graph.dijkstra(1);

    std::cout << std::endl;
    graph.prims();

    return 0;
}

/*
 node id 0  prev 1 distance : 4
 node id 1  prev -1 distance : 0
 node id 2  prev 1 distance : 8
 node id 3  prev 2 distance : 15
 node id 4  prev 5 distance : 22
 node id 5  prev 2 distance : 12
 node id 6  prev 7 distance : 12
 node id 7  prev 1 distance : 11
 node id 8  prev 2 distance : 10

 node id 0  prev 1 distance : 4
 node id 1  prev -1 distance : 0
 node id 2  prev 1 distance : 8
 node id 3  prev 2 distance : 7
 node id 4  prev 3 distance : 9
 node id 5  prev 2 distance : 4
 node id 6  prev 5 distance : 2
 node id 7  prev 6 distance : 1
 node id 8  prev 2 distance : 2
 */

void Graph::shortestPath(int source)// unweighted graph
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> distance(count, -1) ;; // infinite

    std::queue<int> que;
    que.push(source);
    distance[source] = 0;
    while (que.empty() == false)
    {
        int curr = que.front();
        que.pop();
        auto& adl = Adj[curr];
        for (auto adn : adl)
        {
            if (distance[adn.destination] == -1)
            {
                distance[adn.destination] = distance[curr] + 1;
                previous[adn.destination] = curr;
                que.push(adn.destination);
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << previous[i] << " to " << i << " weight " << distance[i]<<std::endl;
    }
}

int main17()
{
    Graph gph = Graph(9);
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
    gph.shortestPath(0);
    return 0;
}

/*
-1 to 0 weight 0
0 to 1 weight 1
1 to 2 weight 2
2 to 3 weight 3
3 to 4 weight 4
2 to 5 weight 3
7 to 6 weight 2
0 to 7 weight 1
7 to 8 weight 2
*/

void Graph::dijkstra(int source)
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;// infinite
    std::vector<bool> visited(count, false) ;

    dist[source] = 0;
    previous[source] = -1;
    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

    Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true)
    {
        node = queue.top();
        queue.pop();

        visited[source] = true;
        source = node->destination;
        auto& adl = Adj[source];
        for (auto adn : adl)
        {
            int dest = adn.destination;
            int alt = adn.cost + dist[source];
            if (dist[dest] > alt && visited[dest] == false)
            {
                dist[dest] = alt;
                previous[dest] = source;
                node = new Edge(dest, alt);
                queue.push(node);
            }
        }
    }
    // printing result.

    for (int i = 0; i < count; i++)
    {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable"<< std::endl;
        else
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i]<< std::endl;
    }
}


void Graph::bellmanFordshortestPath(int source)
{

    std::vector<int> previous(count, -1) ;
    std::vector<int> distance(count, std::numeric_limits<int>::max()) ;

    distance[source] = 0;
    // Outer loop will run (V-1) number of times.
    // Inner for loop and while loop runs combined will
    // run for Edges number of times.
    // Which make the total complexity as O(V*E)

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count; j++)
        {
            auto& adl = Adj[j];
            for (auto adn : adl)
            {
                int newDistance = distance[j] + adn.cost;
                if (distance[adn.destination] > newDistance)
                {
                    distance[adn.destination] = newDistance;
                    previous[adn.destination] = j;
                }

            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        std::cout << previous[i] << " to " << i << " weight " << distance[i] << std::endl;
    }
}

int main18()
{
    Graph gph = Graph(5);
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
-1 to 0 weight 0
4 to 1 weight 0
1 to 2 weight 1
2 to 3 weight 2
0 to 4 weight 2
*/

int Graph::bestFirstSearchPQ(int source, int dest)
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;


    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> pq;

    dist[source] = 0;
    previous[source] = -1;
    Edge* node = new Edge(source, 0);
    pq.push(node);

    while (pq.empty() != true)
    {
        node = pq.top();
        pq.pop();

        source = node->destination;
        if (source == dest)
        {
            return node->cost;
        }
        visited[source] = true;

        auto& adl = Adj[source];
        for (auto adn : adl)
        {
            int curr = adn.destination;
            int cost = adn.cost;
            int alt = cost + dist[source];
            if (dist[curr] > alt && visited[curr] == false)
            {
                dist[curr] = alt;
                previous[curr] = source;
                node = new Edge(curr, alt);
                pq.push(node);
            }
        }
    }
    return -1;
}


/*
 * The function returns one of the following values Return 0 if graph is not
 * Eulerian Return 1 if graph has an Euler previous (Semi-Eulerian) Return 2 if
 * graph has an Euler Circuit (Eulerian)
 */
int Graph::isEulerian()
{
    // Check if all non - zero degree nodes are connected
    int odd;
    if (isConnected() == false)
    {
        std::cout << "graph is not Eulerian" << std::endl;
        return 0;
    }
    else
    {
        // Count odd degree
        odd = 0;
        std::vector<int> inDegree(count, 0);
        std::vector<int> outDegree(count, 0);

        for (int i = 0; i < count; i++)
        {
            inDegree[i] = 0;
            outDegree[i] = 0;
        }
        for (int i = 0; i < count; i++)
        {
            auto& adl = Adj[i];
            for (auto adn : adl)
            {
                outDegree[i] += 1;
                inDegree[adn.destination] += 1;
            }
        }
        for (int i = 0; i < count; i++)
        {
            if ((inDegree[i] + outDegree[i]) % 2 != 0)
            {
                odd += 1;
            }
        }
    }

    if (odd == 0)
    {
        std::cout << "graph is Eulerian" << std::endl;
        return 2;
    }
    else if (odd == 2)
    {
        std::cout << "graph is Semi-Eulerian" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "graph is not Eulerian" << std::endl;
        return 0;
    }
}

int main19()
{
    Graph gph = Graph(5);
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


bool Graph::isStronglyConnected2()
{

    std::vector<bool> visited(count, false);
    int index;
    // Find a vertex with non - zero degree
    for (index = 0; index < count; index++)
    {
        auto& adl = Adj[index];
        if (adl.size() > 0)
            break;
    }
    // dfs traversal of graph from a vertex with non - zero degree
    dfsUtil(index, visited);
    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[index];
        if (visited[i] == false && adl.size() > 0)
            return false;
    }

    Graph gReversed = Graph(count);
    transposeGraph(gReversed);
    for (int i = 0; i < count; i++)
        visited[i] = false;

    gReversed.dfsUtil(index, visited);

    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        if (visited[i] == false && adl.size() > 0)
            return false;
    }
    return true;
}

bool Graph::isEulerianCycle()
{
    // Check if all non - zero degree count are connected

    std::vector<int> inDegree(count, 0);
    std::vector<int> outDegree(count, 0);

    if (!isStronglyConnected2())
        return false;

    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < count; i++)
    {
        auto& adl = Adj[i];
        for (auto adn : adl)
        {
            outDegree[i] += 1;
            inDegree[adn.destination] += 1;
        }
    }
    for (int i = 0; i < count; i++)
        if (inDegree[i] != outDegree[i])
            return false;
    return true;
}

int main20()
{
    Graph gph = Graph(5);
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

int main()
{
    /* 
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
    */
    main12();
    /*
    main13();
    main14();
    main15();
    main16();
    main17();
    main18();
    main19();
    main20();
    */
    return 0;
}