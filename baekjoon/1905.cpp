#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Lx, Ly;
int data[4000002], lazy[4000002];

struct Point
{
	int x, y;

	bool operator<(const Point &p)
	{
		return this->x < p.x && this->y < p.y;
	}

	bool operator<=(const Point &p)
	{
		return this->x <= p.x && this->y <= p.y;
	}

	bool operator!=(const Point &p)
	{
		return this->x != p.x || this->y != p.y;
	}
};

bool isOutside(Point s1, Point s2, Point e1, Point e2)
{
	if(e2.y < s1.y || s2.y < e1.y)
		return true;
	if(e2.x < s1.x || s2.x < e1.x)
		return true;
	return false;
}

void computeLazy(Point start, Point end, int idx)
{
	data[idx] = max(data[idx], lazy[idx]);

	if(start != end)
	{
		for(int i = 0; i < 4; i++)
			lazy[4 * idx - 2 + i] = max(lazy[4 * idx - 2 + i], lazy[idx]);
	}

	lazy[idx] = 0;
}

int get(Point u, Point v, Point start = {0, 0}, Point end = {999, 999}, int idx = 1)
{
	if(!(start <= end))
		return 0;

	computeLazy(start, end, idx);
	if(u <= start && end <= v)
		return data[idx];
	if(isOutside(u, v, start, end))
		return 0;

	int midx = (start.x + end.x) / 2, midy = (start.y + end.y) / 2;

	int ret = 0;

	ret = max(ret, get(u, v, start, {midx, midy}, 4 * idx - 2));
	ret = max(ret, get(u, v, {start.x, midy + 1}, {midx, end.y}, 4 * idx - 1));

	ret = max(ret, get(u, v, {midx + 1, start.y}, {end.x, midy}, 4 * idx));
	ret = max(ret, get(u, v, {midx + 1, midy + 1}, end, 4 * idx + 1));

	return ret;
}

int update(Point u, Point v, int h, Point start = {0, 0}, Point end = {999, 999}, int idx = 1)
{
	if(!(start <= end))
		return 0;

	if(u <= start && end <= v)
	{
		lazy[idx] = max(lazy[idx], h);
		computeLazy(start, end, idx);

		return data[idx];
	}

	computeLazy(start, end, idx);

	if(isOutside(u, v, start, end))
		return data[idx];

	int midx = (start.x + end.x) / 2, midy = (start.y + end.y) / 2;

	int ret = 0;

	ret = max(ret, update(u, v, h, start, {midx, midy}, 4 * idx - 2));
	ret = max(ret, update(u, v, h, {start.x, midy + 1}, {midx, end.y}, 4 * idx - 1));

	ret = max(ret, update(u, v, h, {midx + 1, start.y}, {end.x, midy}, 4 * idx));
	ret = max(ret, update(u, v, h, {midx + 1, midy + 1}, end, 4 * idx + 1));

	return data[idx] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Lx >> Ly >> N;

	for(int i = 0; i < N; i++)
	{
		int lx, ly, lz, px, py;
		cin >> lx >> ly >> lz >> px >> py;

		Point start = {px, py};
		Point end = {px + lx - 1, py + ly - 1};
		lz += get(start, end);

		update(start, end, lz);
	}

	cout << get({0, 0}, {Lx - 1, Ly - 1}) << '\n';
}