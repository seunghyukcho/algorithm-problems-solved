#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[4002];
int N, M, T, cache[4002][2];
bool visited[4002], visited2[4002][4002];

int dfs(int here)
{
	int ret = 1;
	for(int next : graph[here])
	{
		if(!visited[next])
		{
			visited[next] = true;
			ret += dfs(next);
		}
	}

	return ret;
}

void dfs2(int here, string& ret)
{
	ret[here - 1] = '1';
	visited[here] = true;
	for(int next : graph[here])
	{
		if(!visited[next]) dfs2(next, ret);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string ans;
		cout << "Case #" << t << ": ";
		cin >> N >> M;
		for(int i = 1; i <= N; i++)
		{
			ans += "0";
			visited[i] = false;
			cache[i][0] = cache[i][1] = 0;
			graph[i].clear();
			// for(int j = 1; j <= N; j++)
				// visited2[i][j] = false;
		}

		for(int i = 0; i < M; i++)
		{
			int l, r;
			cin >> l >> r;
			if(l > r) swap(l, r);
			for(int j = 0; j < (r - l + 1) / 2; j++)
			{
				int start = l + j, end = r - j;
				// if(visited2[start][end]) break;
				graph[start].push_back(end);
				graph[end].push_back(start);
				// visited2[start][end] = true;
			}
		}

		vector<pair<int, int> > v;
		v.push_back({0, 0});
		for(int here = 1; here <= N; here++)
			if(!visited[here])
			{
				visited[here] = true;
				v.push_back({here, dfs(here)});
			}

		for(int i = 1; i < v.size(); i++)
		{
			for(int j = 0; j < i; j++)
			{
				int sum = v[i].second + cache[j][0];
				if(sum > N / 2) continue;
				if(sum > cache[i][0])
					cache[i][0] = sum, cache[i][1] = j;
			}
		}

		int start = 0, mx = 0;
		for(int i = 1; i < v.size(); i++)
			if(mx < cache[i][0])
				start = i;

		for(int i = 1; i <= N; i++) visited[i] = false;

		for(; start != 0; start = cache[start][1])
			dfs2(v[start].first, ans);

		cout << ans << '\n';
	}
}