#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sum(vector<int> v1, vector<int> v2)
{
	if(v1.size() > v2.size())
		return sum(v2, v1);
	vector<int> ret(v2.size());

	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	for(int i = 0; i < v1.size(); i++)
		ret[i] = v1[i] + v2[i];
	for(int i = v1.size(); i < v2.size(); i++)
		ret[i] = v2[i];

	for(int i = 0; i < v2.size() - 1; i++)
	{
		ret[i + 1] += ret[i] / 10;
		ret[i] %= 10;
	}

	while(ret[ret.size() - 1] / 10 != 0)
	{
		ret.push_back(ret[ret.size() - 1] / 10);
		ret[ret.size() - 2] %= 10;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int comp(vector<int>& v1, vector<int>& v2)
{
	if(v1.size() == v2.size())
	{
		for(int i = 0; i < v1.size(); i++)
		{
			if(v1[i] != v2[i])
				return v1[i] < v2[i] ? 1 : -1;
		}

		return 0;
	}
	else
	{
		return v1.size() < v2.size() ? 1 : -1;
	}
}

int l;

int main()
{
	cin >> l;
	vector<int> num(l);

	for(int i = 0; i < l; i++)
	{
		char ch;
		cin >> ch;
		num[i] = ch - '0';
	}

	int start = l / 2, end = start + 1;

	while(num[start] == 0)
	{
		start--;
	}
	while(num[end] == 0)
	{
		end++;
	}

	vector<int> ans1 = sum(vector<int>(&num[0], &num[end]), vector<int>(&num[end], &num[l]));
	vector<int> ans2;

	if(start > 0)
	{
		ans2 = sum(vector<int>(&num[0], &num[start]), vector<int>(&num[start], &num[l]));
	}

	if(ans2.size() != 0 && comp(ans1, ans2) == -1)
	{
		for(int i : ans2)
			cout << i;
	}
	else
		for(int i : ans1)
			cout << i;

	cout << '\n';
}