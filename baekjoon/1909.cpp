#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, Wx, Wy, sx, sy, ex, ey;
int area[1002][1002], dist[1002][1002];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
vector<int> yPoints[1002], xPoints[1002];
vector<int> xs, ys;

int findMin(vector<int>& v, int num)
{
	int ret = 1e9;
	auto it = lower_bound(v.begin(), v.end(), num);

	if(it != v.end())
	{
		ret = min(ret, (int)pow(num - *it, 2));
	}

	if(it != v.begin() && (it == v.end() || *it != num))
	{
		it--;
		ret = min(ret, (int)pow(num - *it, 2));
	}

	return ret;
}

bool check(int mid)
{
	bool flag = false;

	for(int i = 1; i <= Wx; i++)
		for(int j = 1; j <= Wy; j++)
			area[i][j] = (dist[i][j] < mid ? 0 : 1);

	if(area[sx][sy] && area[ex][ey])
	{
		queue<pair<int, int> > q;
		q.push({sx, sy});

		while(!q.empty() && !flag)
		{
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			for(int k = 0; k < 4 && !flag; k++)
			{
				int nextx = x + dir[k][0], nexty = y + dir[k][1];

				if(nextx <= 0 || nextx > Wx || nexty <= 0 || nexty > Wy || !area[nextx][nexty])
					continue;
				else if(nextx == ex && nexty == ey)
					flag = true;
				else
				{
					q.push({nextx, nexty});
					area[nextx][nexty] = 0;
				}
			}
		}
	}

	return flag;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Wx >> Wy;
	cin >> sx >> sy >> ex >> ey;
	cin >> n;

	for(int i = 1; i <= Wx; i++)
		for(int j = 1; j <= Wy; j++)
			dist[i][j] = 1e9;

	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		if(xPoints[x].empty())
			xs.push_back(x);
		if(yPoints[y].empty())
			ys.push_back(y);

		xPoints[x].push_back(y);
		yPoints[y].push_back(x);
		dist[x][y] = 0;
	}

	for(auto v : yPoints)
		sort(v.begin(), v.end());
	for(auto v : xPoints)
		sort(v.begin(), v.end());
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	for(int i = 1; i <= Wx; i++)
	{
		for(int j = 1; j <= Wy; j++)
		{
			if(dist[i][j] == 1e9)
			{
				auto it = lower_bound(xs.begin(), xs.end(), i);

				if(it != xs.end())
				{
					dist[i][j] = min(dist[i][j], (int)pow(i - *it, 2) + findMin(xPoints[*it], j));
				}

				else if(it != xs.begin() && (it == xs.end() || *it != i))
				{
					it--;
					dist[i][j] = min(dist[i][j], (int)pow(i - *it, 2) + findMin(xPoints[*it], j));
				}

				it = lower_bound(ys.begin(), ys.end(), j);

				if(it != ys.end())
				{
					dist[i][j] = min(dist[i][j], (int)pow(j - *it, 2) + findMin(yPoints[*it], i));
				}

				else if(it != ys.begin() && (it == ys.end() || *it != j))
				{
					it--;
					dist[i][j] = min(dist[i][j], (int)pow(j - *it, 2) + findMin(yPoints[*it], i));
				}
			}
		}
	}

	int start = 0, end = 2000000;
	while(start + 1 < end)
	{
		int mid = (start + end) / 2;

		if(check(mid))
			start = mid;
		else
			end = mid - 1;
	}

	cout << (check(end) ? end : start) << '\n';
}