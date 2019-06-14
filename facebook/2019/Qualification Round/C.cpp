#include <iostream>
#include <string>

using namespace std;

pair<int, int> ans(string &s, int pos)
{
	if(s[pos] != '(')
	{
		pair<int, int> ret = {0, pos + 1};
		
		if(s[pos] == '0' || s[pos] == '1')
			ret.first = s[pos] - '0';
		else if(s[pos] == 'x')
			ret.first = 3;
		else
			ret.first = 4;

		return ret;
	}

	auto result1 = ans(s, pos + 1);
	auto result2 = ans(s, result1.second + 1);

	int left = result1.first;
	int right = result2.first;
	char op = s[result1.second];

	pair<int, int> ret = {2, result2.second + 1};
	if(op == '|')
	{
		if(right <= 1 && left <= 1)
			ret.first = right | left;
		else if(right == 1 || left == 1)
			ret.first = 1;
		else if(right + left == 7)
			ret.first = 1;

	}

	return ret;
}

int main()
{
	int t, T;
	cin >> T;

	for(t = 1; t <= T; t++)
	{
		string s;

		cout << "Case #" << t << ": ";
		cin >> s;

		auto ret = ans(s, 0);
		cout << ret.first << ' ' << ret.second << '\n';
	}

	return 0;
}