#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct C {
	int x, y;
} coor[52];

int n, ans;
bool visited[52];

int dfs(int idx, int p, int q)
{
	visited[idx] = true;

	for(int i = 0; i < n; i++)
	{
		int xdiff = coor[i].x - coor[idx].x;
		int ydiff = coor[i].y - coor[idx].y;

		if(xdiff == p && ydiff == q)
		{
			if(!visited[i])
				return dfs(i, p, q);
			else
				return 0;
		}
	}

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> coor[i].x >> coor[i].y;
	
	ans = 1e9;
	for(int c1 = 0; c1 < n; c1++)
	{
		for(int c2 = 0; c2 < n; c2++)
		{
			int p = coor[c2].x - coor[c1].x;
			int q = coor[c2].y - coor[c1].y;

			if(p == 0 && q == 0)
				continue;

			int result = 0;
			for(int i = 0; i < n; i++)
				visited[i] = false;

			for(int i = 0; i < n; i++)
			{
				if(!visited[i])
					result += dfs(i, p, q);
			}

			ans = min(ans, result);
		}
	}

	cout << (n == 1 ? 1 : ans) << '\n';
}