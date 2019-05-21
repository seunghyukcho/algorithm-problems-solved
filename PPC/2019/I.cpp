#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int next, c, d;
};

struct Node
{
	int idx, sumC, sumD;

	int cost()
	{
		return sumC * sumD;
	}
};

bool operator<(Node n1, Node n2)
{
	return n1.cost() > n2.cost();
}

int N, M;
vector<Edge> graph[1002];

int dijkstra(int start, int end)
{
	vector<int> dist(1002, -1);
	priority_queue<Node> pq;

	pq.push({start, 0, 0});

	while(!pq.empty())
	{
		Node here = pq.top();
		pq.pop();

		if(dist[here.idx] != -1 && dist[here.idx] < here.cost())
			continue;
		if(here.idx == end)
			return here.cost();
		dist[here.idx] = here.cost();

		cout << here.idx << ' ' << here.sumC << ' ' << here.sumD << '\n';

		for(Edge edge : graph[here.idx])
		{
			int next = edge.next;
			int cost = (here.sumC + edge.c) * (here.sumD + edge.d);

			if((dist[next] == -1 || dist[next] >= cost) && here.sumC + edge.c <= 1000 && here.sumD + edge.d <= 1000)
			{
				pq.push({next, here.sumC + edge.c, here.sumD + edge.d});
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		int here;
		Edge edge;

		cin >> here >> edge.next >> edge.c >> edge.d;
		graph[here].push_back(edge);
	}

	cout << dijkstra(0, N - 1) << '\n';
}