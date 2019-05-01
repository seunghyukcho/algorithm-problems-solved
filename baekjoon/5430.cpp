#include <iostream>
#include <deque>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int t, n;
deque<int> dq;
string s, in;

char ch;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(cin >> t; t > 0; t--)
	{
		cin >> s >> n >> in;

		stringstream ss(in);
		ss >> ch;

		dq.clear();
		for(int i = 0; i < n; i++)
		{
			int num;
			ss >> num >> ch;
			dq.push_back(num);
		}

		int dir = 1;

		for(char ch : s)
		{
			if(ch == 'R')
				dir *= -1;
			else if(ch == 'D')
			{
				if(dq.empty())
				{
					cout << "error\n";
					dir = 0;
					break;
				}

				(dir == 1 ? dq.pop_front() : dq.pop_back());
			}
		}

		if(dir != 0)
		{
			int sz = dq.size();

			cout << '[';
			for(int i = 0; i < sz; i++)
			{
				cout << (dir == 1 ? dq.front() : dq.back()) << (i == sz - 1 ? ']' : ',');
				dir == 1 ? dq.pop_front() : dq.pop_back();
			}
			if(sz == 0)
				cout << "]";

			cout << '\n';
		}
	}
}