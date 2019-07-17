#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

struct Point
{
	int x, y;
} P[500002];

bool compx(Point& p1, Point& p2)
{
	return p1.x < p2.x;
}

bool compy(Point& p1, Point& p2)
{
	return p1.y < p2.y;
}

bool comp(Point& p1, Point& p2)
{
	return p1.y == p2.y ? p1.x > p2.x : p1.y > p2.y;
}

int T, N, M;
int data[]
map<int, int> x_val, y_val;

ll min(ll a, ll b)
{
	return a < b ? a : b;
}

Point query2(int pos, int y1, int y2, int start = 1, int end = N, int v = 1)
{

}

Point query1(int x1, int y1, int x2, int y2, int start = 1, int end = N, int v = 1)
{
	if(x1 <= start && x2 <= end)
		return query2(v, y1, y2);
	if(x2 < start || end < x1)
		return { -1, -1 };

	int mid = (x1 + x2) / 2;

	Point p1 = query1(x1, y1, x2, y2, start, mid, 2 * v), p2 = query1(x1, y1, x2, y2, mid + 1, end, 2 * v + 1);

	if(p1.x == -1)
		return p2;
	else if(p2.x == -1)
		return p1;
	else
	{
		int xx1 = x_val[p1.x], yy1 = y_val[p1.y];
		int xx2 = x_val[p2.x], yy2 = y_val[p2.y];
		int dis1 = max(abs(xx1 - x1), abs(yy1 - y1)), dis2 = max(abs(xx2 - x1), abs(yy2 - y1));

		if(dis1 < dis2)
			return p2;
		else 
			return p1;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		ll ans = 0;
		x_val.clear(), y_val.clear();

		cout << "Case #" << t << '\n';
		cin >> M >> N;

		for (int i = 0; i < N; i++)
			cin >> P[i].x >> P[i].y;

		sort(P, P + N, compx);
		for(int i = 0; i < N; i++)
		{
			if(!x_val.find(P[i].x)) x_val[P[i].x] = i + 1;
			P[i].x = x_val[P[i].x];
		}

		sort(P, P + N, compy);
		for(int i = 0; i < N; i++)
		{
			if(!y_val.find(P[i].y)) y_val[P[i].y] = i + 1;
			P[i].y = y_val[P[i].y];
		}

		sort(P, P + N, comp);

		cout << ans << '\n';
	}
}