#include "GraphAM.h"

GraphAM::GraphAM(int cnt)
{
    count = cnt;
    adj = std::vector<std::vector<int>>(cnt, std::vector<int>(cnt, 0));
}

void GraphAM::addDirectedEdge(int src, int dst, int cost)
{
    adj[src][dst] = cost;
}

void GraphAM::addDirectedEdge(int src, int dst)
{
    adj[src][dst] = 1;
}

void GraphAM::addUndirectedEdge(int src, int dst, int cost)
{
    addDirectedEdge(src, dst, cost);
    addDirectedEdge(dst, src, cost);
}

void GraphAM::addUndirectedEdge(int src, int dst)
{
    addUndirectedEdge(src, dst, 1);
}

void GraphAM::print()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "Node index [ " << i << " ] is connected with : " ;
        for (int j = 0; j < count; j++)
        {
            if (adj[i][j] != 0)
                std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

/* Testing Code */
int main1()
{
    GraphAM graph = GraphAM(4);
    graph.addUndirectedEdge(0, 1, 1);
    graph.addUndirectedEdge(0, 2, 1);
    graph.addUndirectedEdge(1, 2, 1);
    graph.addUndirectedEdge(2, 3, 1);
    graph.print();
    return 0;
}

/*
Node index [ 0 ] is connected with : 1 2
Node index [ 1 ] is connected with : 0 2
Node index [ 2 ] is connected with : 0 1 3
Node index [ 3 ] is connected with : 2
*/

bool GraphAM::EdgeComparator::operator()(Edge *x, Edge *y)
{
    if (x->cost <= y->cost)
    {
        return false;
    }
    return true;
}


void GraphAM::dijkstra(int source)
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
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
        source = node->dest;
        visited[source] = true;
        for (int dest = 0; dest < count; dest++)
        {
            int cost = adj[source][dest];
            if (cost != 0)
            {
                int alt = cost + dist[source];
                if (dist[dest] > alt && visited[dest] == false)
                {

                    dist[dest] = alt;
                    previous[dest] = source;
                    node = new Edge(dest, alt);
                    queue.push(node);
                }
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
        else
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;
    }
}

void GraphAM::prims()
{
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;

    int source = 0;
    dist[source] = 0;
    previous[source] = -1;

    std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

    Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true)
    {
        node = queue.top();
        queue.pop();
        source = node->dest;
        visited[source] = true;
        for (int dest = 0; dest < count; dest++)
        {
            int cost = adj[source][dest];
            if (cost != 0)
            {
                int alt = cost;
                if (dist[dest] > alt && visited[dest] == false)
                {

                    dist[dest] = alt;
                    previous[dest] = source;
                    node = new Edge(dest, alt);
                    queue.push(node);
                }
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (dist[i] == std::numeric_limits<int>::max())
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
        else
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;
    }
}

/* Testing Code */
int main2()
{
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

    gph.dijkstra(1);
    gph.prims();
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


 node id 0  prev -1 distance : 0
 node id 1  prev 0 distance : 4
 node id 2  prev 5 distance : 4
 node id 3  prev 2 distance : 7
 node id 4  prev 3 distance : 9
 node id 5  prev 6 distance : 2
 node id 6  prev 7 distance : 1
 node id 7  prev 0 distance : 8
 node id 8  prev 2 distance : 2
 */


bool GraphAM::hamiltonianPathUtil(std::vector<int>& path, int pSize, std::vector<int>& added)
{
    // Base case full length path is found
    if (pSize == count)
    {
        return true;
    }
    for (int vertex = 0; vertex < count; vertex++)
    {
        // there is a path from last element and next vertex
        // and next vertex is not already included in path.
        if (pSize == 0 || (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0))
        {
            path[pSize++] = vertex;
            added[vertex] = 1;
            if (hamiltonianPathUtil(path, pSize, added))
                return true;
            // backtracking
            pSize--;
            added[vertex] = 0;
        }
    }
    return false;
}

bool GraphAM::hamiltonianPath()
{
    std::vector<int> path(count);
    std::vector<int> added(count);

    if (hamiltonianPathUtil(path, 0, added))
    {
        std::cout << "\nHamiltonian Path found :: ";
        for (int i = 0; i < count; i++)
            std::cout << " " << path[i];

        return true;
    }

    std::cout << "\nHamiltonian Path not found";
    return false;
}

/* Testing Code */
int main3()
{
    int count = 5;
    GraphAM graph = GraphAM(count);
    std::vector<std::vector<int>> adj = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 }, { 0, 1, 1, 1, 0 } };

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (adj[i][j] == 1)
                graph.addDirectedEdge(i, j, 1);
    graph.hamiltonianPath();

    GraphAM graph2 = GraphAM(count);
    std::vector<std::vector<int>> adj2 = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 0 }
    };
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

bool GraphAM::hamiltonianCycleUtil(std::vector<int>& path, int pSize, std::vector<int>& added)
{
    // Base case full length path is found
    // this last check can be modified to make it a path.
    if (pSize == count)
    {
        if (adj[path[pSize - 1]][path[0]] == 1)
        {
            path[pSize] = path[0];
            return true;
        }
        else
            return false;
    }
    for (int vertex = 0; vertex < count; vertex++)
    {
        // there is a path from last element and next vertex
        if (pSize == 0 || (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0))
        {
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

bool GraphAM::hamiltonianCycle()
{
    std::vector<int> path(count+1);
    std::vector<int> added(count);

    if (hamiltonianCycleUtil(path, 0, added))
    {
        std::cout << "\nHamiltonian Cycle found :: ";
        for (int i = 0; i <= count; i++)
            std::cout << " " << path[i];
        return true;
    }
    std::cout << "\nHamiltonian Cycle not found";
    return false;
}



/* Testing Code */
int main()
{
    int count = 5;
    GraphAM graph = GraphAM(count);
    std::vector<std::vector<int>> adj = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 }, { 0, 1, 1, 1, 0 } };

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (adj[i][j] == 1)
                graph.addDirectedEdge(i, j, 1);
    graph.hamiltonianCycle();

    GraphAM graph2 = GraphAM(count);
    std::vector<std::vector<int>> adj2 = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 0 }
    };
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
