#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

struct Point
{
	int idx, x, y;
} P[500002];

bool comp(Point& p1, Point& p2)
{
	return p1.y == p2.y ? p1.x > p2.x : p1.y > p2.y;
}

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

int T, N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		ll ans = 0;
		cout << "Case #" << t << '\n';
		cin >> M >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> P[i].x >> P[i].y;
		}

		sort(P, P + N, comp);

		for(int i = 0; i < N; i++)
		{
			ll result = min(abs(M - P[i].x), abs(M - P[i].y));

			for(int j = 0; j < i; j++)
			{
				if(P[j].x <= P[i].x || P[j].y == P[i].y)
					continue;
				result = min(result, max(abs(P[j].x - P[i].x), abs(P[j].y - P[i].y)));
			}

			ans += result;
		}

		cout << ans << '\n';
	}
}