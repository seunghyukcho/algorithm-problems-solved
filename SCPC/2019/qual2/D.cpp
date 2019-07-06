#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#define MAX 25002

using namespace std;

typedef pair<int, int> coor;

int T, N, M, map[52][502];
string s;
vector<coor> ans;

int count_bombs(int x, int y)
{
	int ret = 0;
	for(int r = x - 1; r <= x + 1; r++)
		for(int c = y - 1; c <= y + 1; c++)
			ret += map[r][c];
	return ret;
}

void convert_bombs(int x, int y)
{
	for(int r = x - 1; r <= x + 1; r++)
		for(int c = y - 1; c <= y + 1; c++)
			map[r][c] = 0;
}

int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		ans.clear();
		cout << "Case #" << t << '\n';
		cin >> M >> N;

		for(int i = 0; i < M; i++)
		{
			cin >> s;
			for(int j = 0; j < N; j++)
				map[i][j] = s[j] - '0';
		}
		
		for(int r = 0; r < M - 1; r++)
			for(int c = 0; c < N; c++)
			{
				if(map[r][c] == 0) continue;

				int mx = -1;
				coor result;
				for(int dir = -1; dir < 2; dir++)
				{
					if(c + dir < 0 || c + dir >= N)
						continue;
					int cnt = count_bombs(r + 1, c + dir);
					if(mx < cnt)
					{
						mx = cnt;
						result = { r + 1, c + dir };
					}
				}

				convert_bombs(result.first, result.second);
				ans.push_back(result);
			}

		for(int c = 0; c < N; c++)
		{
			if(map[M - 1][c] == 0) continue;

			if(c == 0)
			{
				convert_bombs(M - 1, 1);
				ans.push_back({ M - 1, 1 });
			}
			else if(c == N - 1)
				ans.push_back({ M - 1, N - 2 });
			else
			{
				convert_bombs(M - 1, c);
				ans.push_back({ M - 1, c });
			}
		}

		cout << ans.size() << '\n';
		for(coor p : ans)
			cout << p.first << ' ' << p.second << '\n';
	}
}