#include <iostream>

using namespace std;

bool visited[402][402], f;
int T, r, c;

bool dfs(int x, int y)
{
	bool ret = true;

	for(int i = 0; ret && i < r; i++)
		for(int j = 0; ret && j < c; j++)
		{
			if(!visited[i][j])
				ret = false;
		}

	for(int i = 0; !ret && i < r; i++)
		for(int j = 0; !ret && j < c; j++)
		{
			if(!visited[i][j])
			{
				if(i != x && j != y && (x + y != i + j) && (y - x != j - i))
				{
					visited[i][j] = true;
					ret = dfs(i, j);
					visited[i][j] = false;
				}
			}
		}

	if(ret)
	{
		if(f)
		{
			printf("POSSIBLE\n");
			f = false;
		}
		printf("%d %d\n", x + 1, y + 1);
	}
	return ret;
}

int main()
{
	int t = 1;
	for(scanf("%d", &T); t <= T; t++)
	{
		bool ans = false;
		f = true;
		printf("Case #%d: ", t);
		scanf("%d %d", &r, &c);

		for(int i = 0; !ans && i < r; i++)
			for(int j = 0; !ans && j < c; j++)
			{
				visited[i][j] = true;
				ans = dfs(i, j);
				visited[i][j] = false;
			}

		if(!ans) 
			printf("IMPOSSIBLE\n");
	}
}