#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
	int idx, start, end, flow;
};

vector<Edge> E;
vector<int> V[1010];
int source, sink;

void setEdge(int u, int v, int c)
{
	int sz = E.size();
	Edge edge1 = {sz, u, v, c}, edge2 = {sz + 1, v, u, 0};
	V[u].push_back(sz);
	V[v].push_back(sz + 1);

	E.push_back(edge1);
	E.push_back(edge2);
}

void bfs(vector<int>& level)
{
	queue<int> q;
	for(int i = 0; i < 1010; i++) level[i] = -1;
	level[source] = 0;
	q.push(source);

	while(!q.empty())
	{
		int here = q.front(); q.pop();
		for(int idx : V[here])
		{
			Edge e = E[idx];
			int next = e.end, flow = e.flow;

			if(flow > 0 && level[next] == -1)
			{
				level[next] = level[here] + 1;
				q.push(next);
			}
		}
	}
}

int dfs(int here, vector<int>& start, vector<int>& level, int minFlow = 1e9)
{
	if(here == sink) return minFlow;

	int sz = V[here].size(), f = 0;
	for(int& idx = start[here]; idx < sz; idx++)
	{
		Edge e = E[V[here][idx]];
		int next = e.end, flow = e.flow;
		if(level[here] + 1 == level[next] && e.flow > 0)
		{
			f = dfs(next, start, level, min(minFlow, flow));
			if(f > 0)
			{
				E[e.idx].flow -= f;
				E[e.idx ^ 1].flow += f;
				return f;
			}
		}
	}

	return f;
}

int maxFlow()
{
	int ret = 0;

	while(1)
	{
		vector<int> level(1010), start(1010, 0);
		bfs(level);
		if(level[sink] == -1) break;

		while(1)
		{
			int totalFlow = dfs(source, start, level);
			if(totalFlow == 0) break;
			ret += totalFlow;
		}
	}

	return ret;
}

int main()
{
	int N, M;
	cin >> N >> M;

	source = 0, sink = 2 * N + 1;
	for(int i = 1; i <= N; i++)
	{
		setEdge(source, i, 1);
		setEdge(i + N, sink, 1);
	}

	for(int i = 0; i < M; i++)
	{
		int row, col;
		cin >> row >> col;
		setEdge(row, col + N, 1);
	}

	cout << maxFlow() << '\n';
}