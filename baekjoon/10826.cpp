#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void add(vector<int> a, vector<int> b, vector<int> &ret)
{
	if(a.size() > b.size())
		swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for(int i = 0; i < a.size(); i++)
		ret.push_back(a[i] + b[i]);

	for(int i = a.size(); i < b.size(); i++)
		ret.push_back(b[i]);

	for(int i = 0; i < b.size() - 1; i++)
	{
		ret[i + 1] += ret[i] / 10;
		ret[i] %= 10;
	}

	if(ret.back() > 9)
	{
		int b = ret.back() / 10;
		ret.back() %= 10;
		ret.push_back(b);
	}

	reverse(ret.begin(), ret.end());
}

void print(vector<int> &v)
{
	for(int num : v)
		cout << num;
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	vector<int> n1, n2;
	n1.push_back(0);
	n2.push_back(1);

	cin >> n;
	if(n == 0)
		print(n1);
	else if(n == 1)
		print(n2);
	else
	{
		for(int i = 0; i < n - 1; i++)
		{
			vector<int> sum;
			add(n1, n2, sum);
			n1 = n2;
			n2 = sum;
		}

		print(n2);
	}

}