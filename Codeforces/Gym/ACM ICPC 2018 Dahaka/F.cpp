#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, Q, K;
int cache[10002][15];
int parent[10002], level[10002];
vector<int> child[10002];

int dp(int n, int k)
{
	int& ret = cache[n][k];

	if(ret != -1)
		return ret;
	if(k == 0)
		return ret = parent[n];
	return ret = dp(dp(n, k - 1), k - 1);
}

int findParent(int u, int n)
{
	for(int i = 0; (1 << i) <= n; i++)
	{
		if((n & (1 << i)) != 0)
			u = dp(u, i);
	}

	return u;
}

int lca(int u, int v)
{
	if(level[u] < level[v])
		return lca(v, u);

	int diff = level[u] - level[v];
	u = findParent(u, diff);

	if(u == v)
		return u;

	int start = 1, end = level[u]; 
	while(start < end)
	{
		int mid = (start + end) / 2;
		int p1 = findParent(u, mid), p2 = findParent(v, mid);

		if(p1 == p2)
			end = mid;
		else
		{
			u = p1, v = p2;
			end -= mid;
		}
	}

	return findParent(u, start);
}

void dfs(int here, int prev)
{
	level[here] = level[prev] + 1;
	parent[here] = prev;

	for(int next : child[here])
	{
		if(next == prev)
			continue;
		dfs(next, here);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N;
		for(int i = 1; i <= N; i++)
		{
			parent[i] = -1;
			level[i] = -1;
			child[i].clear();
			for(int j = 0; j < 15; j++)
				cache[i][j] = -1;
		}

		for(int i = 0; i < N - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			child[u].push_back(v);
			child[v].push_back(u);
		}

		dfs(1, 1);
		cout << "Case " << t << ":\n";
		for(cin >> Q; Q > 0; Q--)
		{
			int start, end, u, v, se;
			bool flag = true;

			cin >> K;
			cin >> start >> end;
			se = lca(start, end);

			for(; K > 1; K--)
			{
				cin >> u >> v;
				if(!flag) continue;

				int p1 = lca(u, se), p2 = lca(v, se);
				if(p1 != se && p2 != se)
					flag = false;
				else if(p1 == se && p2 == se)
				{
					int lca2 = lca(u, v);
					p1 = lca(start, lca2), p2 = lca(end, lca2);

					if(p1 != lca2 && p2 != lca2)
						flag = false;
					else if(p1 == lca2 && p2 == lca2)
					{
						p1 = lca(start, u), p2 = lca(end, v);
						if(p1 == se && p2 == se)
							p1 = lca(start, v), p2 = lca(end, u);

						start = p1, end = p2;
					}
					else if(p1 == lca2)
					{
						p2 = lca2;
						p1 = lca(start, u);
						if(p1 == lca2)
							p1 = lca(start, v);

						start = p1, end = p2;
					}
					else
					{
						p1 = lca2;
						p2 = lca(end, u);
						if(p2 == lca2)
							p2 = lca(end, v);

						start = p1, end = p2;
					}
				}
				else
				{
					if(p1 != se)
						swap(u, v);
					p1 = lca(start, u), p2 = se;
					if(p1 == se)
						p2 = lca(end, u);

					start = p1, end = p2;
				}

				se = lca(start, end);
			}

			if(flag)
				cout << level[start] + level[end] - 2 * level[se] + 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}
