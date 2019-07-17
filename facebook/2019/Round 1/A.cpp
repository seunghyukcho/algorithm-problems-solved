#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

struct C
{
	int x, y, z;
};

vector<C> constraints;
int T, N, M;
ll cache[52][52];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N >> M;
		cout << "Case #" << t << ": ";
		constraints.clear();
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
			{
				cache[i][j] = (i == j ? 0 : LLONG_MAX);
			}
		
		for(int i = 0; i < M; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;

			constraints.push_back({x, y, z});
			cache[x][y] = cache[y][x] = z;
		}

		for(int k = 1; k <= N; k++)
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= N; j++)
				{
					if(cache[i][k] == LLONG_MAX || cache[k][j] == LLONG_MAX)
						continue;
					cache[i][j] = min(cache[i][j], cache[i][k] + cache[k][j]);
				}
				

		bool ans = true;
		for(C p : constraints)
		{
			if(cache[p.x][p.y] != p.z)
			{
				ans = false;
				break;
			}
		}

		if(ans)
		{
			cout << M << '\n';
			for(C p : constraints)
				cout << p.x << ' ' << p.y << ' ' << p.z << '\n';
		}
		else
			cout << "Impossible\n";
	}
}