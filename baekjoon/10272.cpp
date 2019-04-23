#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
	double x, y;
} P[520];

double min(double n1, double n2)
{
	return n1 < n2 ? n1 : n2;
}

double distance(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double cache[520][520];
int N, t;

double dp(int x, int y)
{
	double &ret = cache[x][y];

	if(ret != -1)
		return ret;
	if(x > y)
		return ret = dp(y, x);

	if(x != y - 1)
		return ret = dp(x, y - 1) + distance(P[y - 1], P[y]);
	else
	{
		for(int i = 0; i < x; i++)
		{
			double dist = dp(i, x) + distance(P[i], P[y]);
			ret = (ret == -1 ? dist : min(dist, ret));
		}

		return ret;
	}
}

int main()
{
	cout.unsetf(ios::fixed);
	cout.precision(5);

	for(cin >> t; t > 0; t--)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
		{
			cin >> P[i].x >> P[i].y;
			for(int j = 0; j < N; j++)
				cache[i][j] = -1;
		}

		cache[0][1] = distance(P[0], P[1]);
		cache[1][2] = distance(P[1], P[0]) + distance(P[2], P[0]);
		
		double ans = -1;

		for(int i = 0; i < N - 1; i++)
		{
			double dist = dp(i, N - 1) + distance(P[i], P[N - 1]);
			ans = (ans == -1 ? dist : min(ans, dist));
		}

		cout << ans << '\n';
	}
}