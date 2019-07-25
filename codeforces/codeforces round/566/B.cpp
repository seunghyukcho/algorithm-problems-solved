#include <iostream>
#include <queue>

using namespace std;

int w, h, dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char map[502][502];
bool visited[502][502];

bool outside(int x, int y)
{
	if(x < 0 || x >= w || y < 0 || y >= h)
		return true;
	return false;
}

void dfs(int x, int y)
{
	visited[x][y] = true;
	for(int k = 0; k < 4; k++)
	{
		int nextx = x + dir[k][0], nexty = y + dir[k][1];
		if(outside(nextx, nexty) || map[nextx][nexty] == '.' || visited[nextx][nexty])
			continue;

		dfs(nextx, nexty);
	}
}

int main()
{
	bool flag = true;
	int cnt = 0;

	cin >> w >> h;
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == '*')
				cnt++;
		}

	if(cnt < 5)
	{
		cout << "NO\n";
		return 0;
	}

	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
		{
			if(map[i][j] == '*' && !visited[i][j])
			{
				if(!flag) 
				{
					cout << "NO\n";
					return 0;
				}

				dfs(i, j);
				flag = false;
			}
		}

	for(int i = 1; i < w - 1; i++)
	{
		int cnt2 = 0;
		for(int j = 0; j < h; j++)
			if(map[i][j] == '*')
				cnt2++;

		for(int j = 1; j < h - 1; j++)
		{
			if(map[i][j] != '*')
				continue;
			int cnt3 = 0;
			for(int k = 0; k < w; k++)
				if(map[k][j] == '*')
					cnt3++;

			if(cnt2 + cnt3 == cnt + 1)
			{
				bool ans = true;
				for(int k = 0; ans && k < 4; k++)
				{
					int nextx = i + dir[k][0];
					int nexty = j + dir[k][1];

					if(map[nextx][nexty] != '*')
						ans = false;
				}

				if(ans)
				{
					cout << "YES\n";
					return 0;
				}
			}
		}
	}

	cout << "NO\n";
	return 0;

}