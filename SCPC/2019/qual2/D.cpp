#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#define MAX 25002

using namespace std;

int T, N, M, map[52][502];
int A[MAX], B[MAX], level[MAX];
bool visited[MAX];
vector<int> graph[MAX];

void bfs()
{
	queue<int> q;

	for(int i = 0; i < (N - 2) * (M - 2); i++)
	{
		if(!visited[i])
		{
			level[i] = 0;
			q.push(i);
		}
		else
			level[i] = INT_MAX;
	}

	while(!q.empty())
	{
		int here = q.front(); q.pop();
		for(int next : graph[here])
		{
			if(B[next] != -1 && level[B[next]] == INT_MAX)
			{
				level[B[next]] = level[here] + 1;
				q.push(B[next]);
			}
		}
	}
}

bool dfs(int here)
{
	for(int next : graph[here])
	{
		if(B[next] == -1 || (level[B[next]] == level[here] + 1 && dfs(B[next])))
		{
			visited[here] = true;
			B[next] = here;
			A[here] = next;

			return true;
		}
	}

	return false;
}

int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int ans = 0;
		cout << "Case #" << t << '\n';
		cin >> M >> N;
		for(int i = 0; i < M; i++)
		{
				string s;
				cin >> s;
				for(int j = 0; j < N; j++)
				{
					map[i][j] = s[j] - '0';
					B[i * N + j + 1] = -1;
				}
		}
			

		for(int i = 1; i < M - 1; i++)
			for(int j = 1; j < N - 1; j++)
			{
				int here = (i - 1) * (N - 2) + j;
				graph[here].clear();
				A[here] = -1, visited[here] = false;

				for(int r = -1; r < 2; r++)
					for(int c = -1; c < 2; c++)
					{
						int next = (i + r) * N + (j + c) + 1;
						if(map[i + r][j + c] == 1)
							graph[here].push_back(next);
					}
			}

		while(1)
		{
			bfs();
			int flow = 0;
			for(int i = 1; i <= (N - 2) * (M - 2); i++)
				if(!visited[i] && dfs(i))
					flow++;
			if(flow == 0)
				break;
			ans += flow;
		}

		cout << ans << '\n';
		for(int i = 1; i <= (N - 2) * (M - 2); i++)
		{
			if(visited[i])
				cout << (i - 1) / (N - 2) + 1 << ' ' << (i - 1) % (N - 2) + 1 << '\n';
		}
	}
}