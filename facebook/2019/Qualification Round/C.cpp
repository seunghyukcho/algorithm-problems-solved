#include <iostream>
#include <string>
#include <cmath>

using namespace std;

pair<int, int> ans(string &s, int pos)
{
	if(s[pos] != '(')
		return {s[pos] - '0', pos + 1};

	auto result1 = ans(s, pos + 1);
	auto result2 = ans(s, result1.second + 1);

	int left = result1.first;
	int right = result2.first;
	char op = s[result1.second];

	pair<int, int> ret = {0, result2.second + 1};

	switch(op)
	{
		case '|':
			ret.first = left | right;
			break;
		case '&':
			ret.first = left & right;
			break;
		case '^':
			ret.first = left ^ right;
			break;
	}

	return ret;
}

int main()
{
	int t, T;
	cin >> T;

	for(t = 1; t <= T; t++)
	{
		string s, s1, s2;

		cout << "Case #" << t << ": ";
		cin >> s;
		s1 = s2 = s;
		for(int i = 0; i < s.size(); i++)
		{
			if(s1[i] == 'x')
			{
				s1[i] = '0';
				s2[i] = '1';
			}
			else if(s1[i] == 'X')
			{
				s1[i] = '1';
				s2[i] = '0';
			}
		}

		auto ret1 = ans(s1, 0), ret2 = ans(s2, 0);
		cout << abs(ret1.first - ret2.first) << '\n';
	}

	return 0;
}