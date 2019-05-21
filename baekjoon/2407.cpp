#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> add(vector<int> a, vector<int> b)
{
	if(a.size() > b.size())
		return add(b, a);
	vector<int> ret = vector<int>(b.size());

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for(int i = 0; i < a.size(); i++)
		ret[i] = a[i] + b[i];
	for(int i = a.size(); i < b.size(); i++)
		ret[i] = b[i];

	for(int i = 0; i < b.size() - 1; i++)
	{
		ret[i + 1] += ret[i] / 10;
		ret[i] %= 10;
	}

	for(int i = b.size() - 1; ret[i] / 10 > 0; i++)
	{
		ret.push_back(ret[i] / 10);
		ret[i] %= 10;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

vector<int> cache[102][102];

vector<int> dp(int n, int m)
{
	if(cache[n][m].size() > 0)
		return cache[n][m];
	
	vector<int> &ret = cache[n][m];
	if(m == 0 || n == m)
	{
		ret.push_back(1);
		return ret;
	}

	return ret = add(dp(n - 1, m), dp(n - 1, m - 1));
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> ans = dp(n, m);
	for(int i : ans)
		cout << i;
	cout << '\n';
}