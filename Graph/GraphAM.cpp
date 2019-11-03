#include "GraphAM.h"

GraphAM::GraphAM(int cnt) {
	count = cnt;
	adj = std::vector<std::vector<int>>(cnt, std::vector<int>(cnt, 0));
}

void GraphAM::AddDirectedEdge(int src, int dst, int cost) {
    adj[src][dst] = cost;
}

void GraphAM::AddUndirectedEdge(int src, int dst, int cost) {
    AddDirectedEdge(src, dst, cost);
    AddDirectedEdge(dst, src, cost);
}

void GraphAM::Print() {
    for (int i = 0; i < count; i++) {
        std::cout << "Node index [ " << i << " ] is connected with : " ;
        for (int j = 0; j < count; j++) {
            if (adj[i][j] != 0)
                std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main1() {
    GraphAM* graph = new GraphAM(4);
    graph->AddUndirectedEdge(0, 1, 1);
    graph->AddUndirectedEdge(0, 2, 1);
    graph->AddUndirectedEdge(1, 2, 1);
    graph->AddUndirectedEdge(2, 3, 1);
    graph->Print();
    return 0;
}

bool GraphAM::EdgeComparator::operator()(Edge *x, Edge *y)
{
	if (x->cost <= y->cost)
	{
		return false;
	}
	return true;
}


void GraphAM::Dijkstra(int source) {
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;

    dist[source] = 0;
    previous[source] = -1;

 	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;


    Edge* node = new Edge(source, 0);
    queue.push(node);

    while (queue.empty() != true) {
        node = queue.top();
        queue.pop();
        source = node->dest;
        visited[source] = true;
        for (int dest = 0; dest < count; dest++) {
            int cost = adj[source][dest];
            if (cost != 0) {
                int alt = cost + dist[source];
                if (dist[dest] > alt && visited[dest] == false) {

                    dist[dest] = alt;
                    previous[dest] = source;
                    node = new Edge(dest, alt);
                    queue.push(node);
                }
            }
        }
    }

    for (int i = 0; i < count; i++) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
        } else {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;

        }
    }
}

void GraphAM::Prims() {
    std::vector<int> previous(count, -1) ;
    std::vector<int> dist(count, std::numeric_limits<int>::max()) ;; // infinite
    std::vector<bool> visited(count, false) ;

    int source = 0;
    dist[source] = 0;
    previous[source] = -1;

	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> queue;

    Edge* node = new Edge(source, 0);
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

    for (int i = 0; i < count; i++) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
        } else {
            std::cout << " node id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;

        }
    }
}

int main2() {
    GraphAM* gph = new GraphAM(9);
    gph->AddUndirectedEdge(0, 1, 4);
    gph->AddUndirectedEdge(0, 7, 8);
    gph->AddUndirectedEdge(1, 2, 8);
    gph->AddUndirectedEdge(1, 7, 11);
    gph->AddUndirectedEdge(2, 3, 7);
    gph->AddUndirectedEdge(2, 8, 2);
    gph->AddUndirectedEdge(2, 5, 4);
    gph->AddUndirectedEdge(3, 4, 9);
    gph->AddUndirectedEdge(3, 5, 14);
    gph->AddUndirectedEdge(4, 5, 10);
    gph->AddUndirectedEdge(5, 6, 2);
    gph->AddUndirectedEdge(6, 7, 1);
    gph->AddUndirectedEdge(6, 8, 6);
    gph->AddUndirectedEdge(7, 8, 7);
    gph->Print();
    gph->Prims();
    //gph->Dijkstra(0);
    return 0;
}

int main3() {
    GraphAM* gph = new GraphAM(9);
    gph->AddUndirectedEdge(0, 2, 1);
    gph->AddUndirectedEdge(1, 2, 5);
    gph->AddUndirectedEdge(1, 3, 7);
    gph->AddUndirectedEdge(1, 4, 9);
    gph->AddUndirectedEdge(3, 2, 2);
    gph->AddUndirectedEdge(3, 5, 4);
    gph->AddUndirectedEdge(4, 5, 6);
    gph->AddUndirectedEdge(4, 6, 3);
    gph->AddUndirectedEdge(5, 7, 1);
    gph->AddUndirectedEdge(6, 7, 7);
    gph->AddUndirectedEdge(7, 8, 17);
    gph->Print();
    gph->Prims();
    gph->Dijkstra(1);
    return 0;
}

bool GraphAM::hamiltonianPathUtil(std::vector<int>& path, int pSize, std::vector<int>& added) {
    // Base case full length path is found
    if (pSize == count) {
        return true;
    }
    for (int vertex = 0; vertex < count; vertex++) {
        // there is a path from last element and next vertex
        // and next vertex is not already included in path.
        if (pSize == 0 || (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0)) {
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

bool GraphAM::hamiltonianCycleUtil(std::vector<int>& path, int pSize, std::vector<int>& added) {
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
        if (pSize == 0 || (adj[path[pSize - 1]][vertex] == 1 && added[vertex] == 0)) {
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
    std::vector<int> path(count+1);
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

int main() {
    int count = 5;
    GraphAM* graph = new GraphAM(count);
    std::vector<std::vector<int>> adj = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 }, { 0, 1, 1, 1, 0 } };

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (adj[i][j] == 1)
                graph->AddDirectedEdge(i, j, 1);
    graph->hamiltonianPath();
    graph->hamiltonianCycle();

    GraphAM* graph2 = new GraphAM(count);
    std::vector<std::vector<int>> adj2 = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 0 },
            { 0, 1, 1, 0, 0 } };
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (adj2[i][j] == 1)
                graph2->AddDirectedEdge(i, j, 1);

    graph2->hamiltonianPath();
    graph2->hamiltonianCycle();
}
