#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

vector<P> childs[100002];
int level[100002];
int parent[100002][20];
ll dist[100002][20];
int N, M;

P dp(int n, int k)
{
	int& p = parent[n][k];
	ll& d = dist[n][k];

	if(p != 0)
		return { p, d };

	P next1 = dp(n, k - 1);
	P next2 = dp(next1.first, k - 1);

	p = next2.first, d = next1.second + next2.second;
	if(next1.first == next2.first)
		d = next1.second;

	return { p, d };
}

P findParent(int u, int n)
{
	P ret = { u, 0 };
	for(int i = 0; (1 << i) <= n; i++)
	{
		if(((1 << i) & n) != 0)
		{
			P next = dp(ret.first, i);
			ret.second += next.second;
			ret.first = next.first;
		}
	}

	return ret;
}

P lca(int u, int v)
{
	if(level[u] < level[v])
		return lca(v, u);

	ll ans = 0;
	int diff = level[u] - level[v];
	P next = findParent(u, diff);
	u = next.first, ans = next.second;

	if(u == v)
		return { u, ans };

	int start = 1, end = level[u];
	while(start < end)
	{
		int mid = (start + end) / 2;
		P next1 = findParent(u, mid), next2 = findParent(v, mid);
		if(next1.first == next2.first)
			end = mid;
		else
		{
			end -= mid;
			ans += next1.second + next2.second;
			u = next1.first, v = next2.first;
		}
	}

	P next1 = findParent(u, 1), next2 = findParent(v, 1);
	return { next1.first, ans + next1.second + next2.second };
}

ll query1(int u, int v)
{
	auto [p, d] = lca(u, v);
	return d;
}

int query2(int u, int v, int k)
{
	auto [p, d] = lca(u, v);
	int diff = level[u] - level[p] + 1;
	int start = u, len = k - 1;
	if(diff < k)
	{
		start = v;
		len = level[v] - level[p] - k + diff;
	}

	for(int i = 0; (1 << i) <= len; i++)
	{
		if(((1 << i) & len) != 0)
		{
			P next = dp(start, i);
			start = next.first;
		}
	}

	return start;
}

void dfs(int here, int prev, int cost)
{
	level[here] = level[prev] + 1;
	parent[here][0] = prev;
	dist[here][0] = cost;

	for(P edge : childs[here])
	{
		if(edge.first == prev) continue;
		dfs(edge.first, here, edge.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		childs[u].push_back({v, w});
		childs[v].push_back({u, w});
	}

	level[1] = -1;
	dfs(1, 1, 0);

	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int q, u, v, k;
		cin >> q;
		if(q == 1)
		{
			cin >> u >> v;
			cout << query1(u, v) << '\n';
		}
		else
		{
			cin >> u >> v >> k;
			cout << query2(u, v, k) << '\n';
		}
	}
}
