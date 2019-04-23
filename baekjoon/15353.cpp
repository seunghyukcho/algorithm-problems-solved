#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string a, b;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	if(a.size() > b.size())
		swap(a, b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++)
	{
		ans.push_back(a[i] + b[i] - 2 * '0');
	}

	for(int i = a.size(); i < b.size(); i++)
		ans.push_back(b[i] - '0');

	for(int i = 0; i < b.size() - 1; i++)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}

	for(int i = b.size() - 1; ans[i] / 10 > 0; i++)
	{
		ans.push_back(ans[i] / 10);
		ans[i] %= 10;
	}

	reverse(ans.begin(), ans.end());
	for(int digit : ans)
		cout << digit;
	cout << '\n';
}