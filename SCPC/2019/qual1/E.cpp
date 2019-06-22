#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll max(ll a, ll b)
{
	return a < b ? b : a;
}

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

struct Point
{
	ll x, y;
} P[100002];

bool comp(Point& p1, Point& p2)
{
	return p1.x == p2.x ? abs(p1.y) < abs(p2.y) : p1.x < p2.x;
}

vector<Point> points;
int T, N;
ll l, r;

ll solve(ll pos, vector<Point>& points)
{
	ll ret = LLONG_MAX;

	for(Point& p : points)
		ret = min(ret, max(abs(pos - p.x), abs(p.y)));
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << '\n';

		points.clear();
		ll ans = LLONG_MIN;
		cin >> l >> r >> N;
		for(int i = 0; i < N; i++)
			cin >> P[i].x >> P[i].y;

		if(N > 100)
		{
			cout << 0 << '\n';
			setbuf(stdout, NULL);
			continue;
		}
		sort(P, P + N, comp);

		if(l < P[0].x)
		{
			ll val = LLONG_MAX;

			for(int i = 0; i < N; i++)
				val = min(val, max(abs(l - P[i].x), abs(P[i].y)));
			ans = max(ans, val);
		}
		if(P[N - 1].x < r)
		{
			ll val = LLONG_MAX;

			for(int i = 0; i < N; i++)
				val = min(val, max(abs(r - P[i].x), abs(P[i].y)));
			
			ans = max(ans, val);
		}

		points.push_back(P[0]);
		for(int i = 1; i < N; i++)
			if(P[i].x != P[i - 1].x)
				points.push_back(P[i]);

		int sz = points.size();
		for(int i = 0; i < sz - 1; i++)
		{
			ll start = points[i].x + 1, end = points[i + 1].x - 1;
			ll subAns = 0;

			if(end < l || r < start)
				continue;
			start = max(start, l);
			end = min(end, r);
			
			while(start + 2 < end)
			{
				ll mid1 = (2 * start + end) / 3;
				ll mid2 = (start + end * 2) / 3;

				if(solve(mid1, points) >= solve(mid2, points))
					end = mid2;
				else
					start = mid1 + 1;
			}	

			if(start <= end)
			{
				subAns = max(solve(start, points), solve(end, points));
				if(end - start == 2)
					subAns = max(subAns, solve(start + 1, points));
				ans = max(ans, subAns);
			}
		}

		for(int i = 0; i < sz; i++)
			if(P[i].x >= l && P[i].x <= r)
				ans = max(ans, solve(P[i].x, points));
		cout << ans * 2 << '\n';
		setbuf(stdout, NULL);
	}
}