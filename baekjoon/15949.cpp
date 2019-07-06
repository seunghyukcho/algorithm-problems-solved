#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char map[102][102];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dp = 0, cp = 3, N, M;
vector<pair<int, int> > border[30][4];

bool isPossible(int x, int y)
{
	if(x < 0 || y < 0 || x >= N || y >= M || map[x][y] == 'X')
		return false;
	return true;
}

int main()
{
	cin >> N >> M;
	for(int x = 0; x < N; x++)
		for(int y = 0; y < M; y++)
		{
			cin >> map[x][y];
			if(map[x][y] == 'X')
				continue;

			auto& v = border[map[x][y] - 'A'];

			if(v[0].empty() || v[0][0].second <= y)
			{
				if(v[0][0].second < y)
					v[0].clear();
				v[0].push_back({x, y});
			}
			if(v[1].empty() || v[1][0].first <= x)
			{
				if(v[1][0].first < x)
					v[1].clear();
				v[1].push_back({x, y});
			}
			if(v[2].empty() || v[2][0].second >= y)
			{
				if(v[2][0].second > y)
					v[2].clear();
				v[2].push_back({x, y});
			}
			if(v[3].empty() || v[3][0].first >= x)
			{
				if(v[3][0].first > x)
					v[3].clear();
				v[3].push_back({x, y});
			}
		}

	int here = map[0][0] - 'A';
	while(1)
	{
		cout << char(here + 'A') << '\n';

		bool flag = true;
		for(int i = 0; i < 4; i++)
		{
			int herex = border[here][dp]
		}

		if(flag)
			break;
	}	

	cout << '\n';
}