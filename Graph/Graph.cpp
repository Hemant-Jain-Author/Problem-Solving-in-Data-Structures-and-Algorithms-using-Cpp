#include "Graph.h"

Graph::Edge::Edge(int src, int dst, int cst = 1)
{
	source = src;
	destination = dst;
	cost = cst;
	next = nullptr;
}

Graph::Graph(int cnt)
{
	count = cnt;
	ListVector = std::vector<AdjList*>(cnt);
	for (int i = 0; i < cnt; i++)
	{
		ListVector[i] = new AdjList();
		ListVector[i]->head = nullptr;
	}
}

void Graph::AddEdge(int source, int destination, int cost)
{
	Edge *edge = new Edge(source, destination, cost);
	edge->next = ListVector[source]->head;
	ListVector[source]->head = edge;
}

void Graph::AddEdge(int source, int destination)
{
	AddEdge(source, destination, 1);
}

void Graph::AddBiEdge(int source, int destination, int cost)
{
	AddEdge(source, destination, cost);
	AddEdge(destination, source, cost);
}

void Graph::AddBiEdge(int source, int destination)
{
	AddBiEdge(source, destination, 1);
}

void Graph::Print()
{
	Edge *ad;
	for (int i = 0; i < count; i++)
	{
		ad = ListVector[i]->head;
		if (ad != nullptr)
		{
			std::cout << "Vertex " << i << " is connected to : ";
			while (ad != nullptr)
			{
				std::cout << ad->destination << " ";
				ad = ad->next;
			}
			std::cout << std::endl;
		}
	}
}

bool Graph::EdgeComparator::operator()(Edge *x, Edge *y)
{
	if (x->cost <= y->cost)
	{
		return false;
	}
	return true;
}

void Graph::Dijkstra(int source)
{
	std::vector<int> previous(count);
	std::vector<int> dist(count);

	for (int i = 0; i < count; i++)
	{
		previous[i] = -1;
		dist[i] = std::numeric_limits<int>::max(); // infinite
	}

	dist[source] = 0;
	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> que;
	Edge *edge = new Edge(source, source, 0);
	que.push(edge);

	while (que.empty() != true)
	{
		edge = que.top();
		que.pop();

		if (dist[edge->destination] < edge->cost)
			continue;

		dist[edge->destination] = edge->cost;
		previous[edge->destination] = edge->source;

		AdjList *adl = ListVector[edge->destination];
		Edge *adn = adl->head;
		while (adn != nullptr)
		{
			if (previous[adn->destination] == -1)
			{
				edge = new Edge(adn->source, adn->destination, adn->cost + dist[adn->source]);
				que.push(edge);
			}
			adn = adn->next;
		}
	}

	for (int i = 0; i < count; i++)
	{
		if (dist[i] == std::numeric_limits<int>::max())
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
		}
		else
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;

		}
	}
}

void Graph::Prims()
{
	std::vector<int> previous(count);
	std::vector<int> dist(count);
	int source = 1;

	for (int i = 0; i < count; i++)
	{
		previous[i] = -1;
		dist[i] = std::numeric_limits<int>::max();
	}

	dist[source] = 0;

	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> que;

	Edge *edge = new Edge(source, source, 0);
	que.push(edge);

	while (que.empty() != true)
	{
		edge = que.top();
		que.pop();

		if (dist[edge->destination] < edge->cost)
			continue;

		dist[edge->destination] = edge->cost;
		previous[edge->destination] = edge->source;

		AdjList *adl = ListVector[edge->destination];
		Edge *adn = adl->head;

		while (adn != nullptr)
		{
			if (previous[adn->destination] == -1)
			{
				edge = new Edge(adn->source, adn->destination, adn->cost);
				que.push(edge);
			}
			adn = adn->next;
		}
	}

	// Printing result.
	for (int i = 0; i < count; i++)
	{
		if (dist[i] == std::numeric_limits<int>::max())
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
		}
		else
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;

		}
	}
}

void Graph::Prims2()
{
	std::vector<int> previous(count);
	std::vector<int> dist(count);
	int source = 1;

	for (int i = 0; i < count; i++)
	{
		previous[i] = -1;
		dist[i] = std::numeric_limits<int>::max();
	}

	dist[source] = 0;

	std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> que;

	Edge *edge;
	for (int i = 0; i < count; i++)
	{
		AdjList *adl = ListVector[i];
		Edge *adn = adl->head;
		while (adn != nullptr)
		{
			edge = new Edge(adn->source, adn->destination, adn->cost);
			que.push(edge);
			adn = adn->next;
		}
	}

	while (que.empty() != true)
	{
		edge = que.top();
		que.pop();

		if (dist[edge->destination] < edge->cost)
			continue;

		dist[edge->destination] = edge->cost;
		previous[edge->destination] = edge->source;

		AdjList *adl = ListVector[edge->destination];
		Edge *adn = adl->head;

		while (adn != nullptr)
		{
			if (previous[adn->destination] == -1)
			{
				edge = new Edge(adn->source, adn->destination, adn->cost);
				que.push(edge);
			}
			adn = adn->next;
		}
	}

	// Printing result.
	for (int i = 0; i < count; i++)
	{
		if (dist[i] == std::numeric_limits<int>::max())
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : Unreachable" << std::endl;
		}
		else
		{
			std::cout << " edge id " << i << "  prev " << previous[i] << " distance : " << dist[i] << std::endl;

		}
	}
}


void Graph::TopologicalSortDFS(int index, std::vector<int> &visited, std::stack<int> &stk)
{
	Edge *head = ListVector[index]->head;
	while (head != nullptr)
	{
		if (visited[head->destination] == 0)
		{
			visited[head->destination] = 1;
			TopologicalSortDFS(head->destination, visited, stk);
		}
		head = head->next;
	}
	stk.push(index);
}

void Graph::TopologicalSort()
{
	std::stack<int> stk;
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			TopologicalSortDFS(i, visited, stk);
		}
	}
	while (stk.empty() != true)
	{
		std::cout << stk.top() << " ";
		stk.pop();
	}
}

int Graph::PathExist(int source, int destination)
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	visited[source] = 1;
	DFSRec(source, visited);
	return visited[destination];
}
void Graph::DFS()
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			DFSRec(i, visited);
		}
	}
}

void Graph::DFSRec(int index, std::vector<int> &visited)
{
	Edge *head = ListVector[index]->head;
	while (head != nullptr)
	{
		if (visited[head->destination] == 0)
		{
			visited[head->destination] = 1;
			DFSRec(head->destination, visited);
		}
		head = head->next;
	}
}

void Graph::DFSStack()
{
	std::vector<int> visited(count);
	int curr;
	std::stack<int> stk;
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}

	visited[0] = 1;
	stk.push(0);

	while (stk.empty() == false)
	{
		curr = stk.top();
		stk.pop();
		Edge *head = ListVector[curr]->head;
		while (head != nullptr)
		{
			if (visited[head->destination] == 0)
			{
				visited[head->destination] = 1;
				stk.push(head->destination);
			}
			head = head->next;
		}
	}
}



void Graph::BFSQueue(int index, std::vector<int> &visited)
{
	int curr;
	std::queue<int> que;

	visited[index] = 1;
	que.push(index);

	while (que.empty() == false)
	{
		curr = que.front();
		que.pop();
		Edge *head = ListVector[curr]->head;
		while (head != nullptr)
		{
			if (visited[head->destination] == 0)
			{
				visited[head->destination] = 1;
				que.push(head->destination);
			}
			head = head->next;
		}
	}
}

void Graph::BFS()
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			BFSQueue(i, visited);
		}
	}
}

bool Graph::isConnected()
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	visited[0] = 1;
	DFSRec(0, visited);
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			return false;
		}
	}
	return true;
}

void Graph::ShortestPath(int source)
{
	int curr;
	std::vector<int> distance(count);
	std::vector<int> path(count);

	std::list<int> que;

	for (int i = 0; i < count; i++)
	{
		distance[i] = -1;
	}
	que.push_back(source);
	distance[source] = 0;
	while (que.empty() == false)
	{
		curr = que.front();
		que.pop_front();
		Edge *head = ListVector[curr]->head;
		while (head != nullptr)
		{
			if (distance[head->destination] == -1)
			{
				distance[head->destination] = distance[curr] + 1;
				path[head->destination] = curr;
				que.push_back(head->destination);
			}
			head = head->next;
		}
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << path[i] << " to " << i << " weight " << distance[i] << std::endl;
	}
}

void Graph::BellmanFordShortestPath(int source)
{
	std::vector<int> distance(count);
	std::vector<int> path(count);

	for (int i = 0; i < count; i++)
	{
		distance[i] = std::numeric_limits<int>::max();
	}
	distance[source] = 0;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count; j++)
		{
			Edge *head = ListVector[j]->head;
			while (head != nullptr)
			{
				int newDistance = distance[j] + head->cost;
				if (distance[head->destination] > newDistance)
				{
					distance[head->destination] = newDistance;
					path[head->destination] = j;
				}
				head = head->next;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << path[i] << " to " << i << " weight " << distance[i] << std::endl;
	}
}

void main()
{
	Graph* g = new Graph(9);
	g->AddBiEdge(0, 2, 1);
	g->AddBiEdge(1, 2, 5);
	g->AddBiEdge(1, 3, 7);
	g->AddBiEdge(1, 4, 9);
	g->AddBiEdge(3, 2, 2);
	g->AddBiEdge(3, 5, 4);
	g->AddBiEdge(4, 5, 6);
	g->AddBiEdge(4, 6, 3);
	g->AddBiEdge(5, 7, 1);
	g->AddBiEdge(6, 7, 7);
	g->AddBiEdge(7, 8, 17);

	g->Dijkstra(1);
	//g->Prims();
}

int main89()
{
	Graph *g = new Graph(6);
	g->AddEdge(5, 2);
	g->AddEdge(5, 0);
	g->AddEdge(4, 0);
	g->AddEdge(4, 1);
	g->AddEdge(2, 3);
	g->AddEdge(3, 1);

	std::cout << "Following is a Topological Sort of the given graph." << std::endl;
	g->TopologicalSort();
	return 0;
}
