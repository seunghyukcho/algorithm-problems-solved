#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> convert;

int t, n, m, num;
vector<int> v1[52], v2[52];
string name;

void dfs(int idx, vector<int> &visited, int &ans, int cooks = 0)
{
	if(idx == n)
	{
		ans = min(ans, cooks);
	}
	else
	{
		if(visited[idx])
			dfs(idx + 1, visited, ans, cooks);
		else
		{
			if(ans == cooks + 1)
				return;
			for(int cook : v1[idx])
			{
				for(int p : v2[cook])
					visited[p]++;
				dfs(idx + 1, visited, ans, cooks + 1);
				for(int p : v2[cook])
					visited[p]--;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(cin >> t; t > 0; t--)
	{
		convert.clear();

		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> name;
			convert[name] = i;
			v1[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			v2[i].clear();
			cin >> num;

			for(int j = 0; j < num; j++)
			{
				cin >> name;
				int idx = convert[name];
				v1[idx].push_back(i);
				v2[i].push_back(idx);
			}
		}

		int ans = 1e9;
		vector<int> visited(n + 1, 0);

		dfs(0, visited, ans);
		cout << ans << '\n';
	}
}