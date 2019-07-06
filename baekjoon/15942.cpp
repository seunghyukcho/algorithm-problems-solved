#include <iostream>
#include <vector>

using namespace std;

int N, k, p;

bool isParent(int parent, int child)
{
	while(child > 0)
	{
		if(child == parent)
			return true;
		child /= 2;
	}

	return false;
}

pair<int, int> level(int node)
{
	int onode = node;
	pair<int, int> ret = {0, 0};

	while(node > 0)
	{
		ret.first++;
		node /= 2;
	}
	node = onode;

	while(node <= N)
	{
		ret.second++;
		node *= 2;
	}

	return ret;
}

int main()
{
	int pos1, pos2, pos3;
	int sz1 = 0, sz2 = 0;
	pair<int, int> l;
	cin >> N >> k >> p;
	
	for(int i = 1; i <= N; i++)
	{
		if(i == p)
			continue;
		else if(i < p)
		{
			if(isParent(i, p))
				sz1++;
		}
		else
		{
			if(isParent(p, i))
				sz2++;
		}
	}

	pos1 = 1;
	pos2 = 1 + sz1;
	pos3 = N - sz2 + 1;

	if(pos2 > k || pos3 <= k)
	{
		cout << -1 << '\n';
		return 0;
	}

	for(int i = 1; i <= N; i++)
	{
		if(pos2 == k)
			pos2++;

		if(i == p)
			cout << k << '\n';
		else if(i < p)
		{
			if(isParent(i, p))
				cout << pos1++ << '\n';
			else
				cout << pos2++ << '\n';
		}
		else
		{
			if(isParent(p, i))
				cout << pos3++ << '\n';
			else
				cout << pos2++ << '\n';
		}
	}
}