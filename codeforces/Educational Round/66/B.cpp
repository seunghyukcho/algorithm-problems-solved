#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n;
bool overflow;
string command;
ll x;

ll solve(int& cnt)
{
	ll ret = 0;

	while(!overflow)
	{
		string s;
		cin >> s;
		cnt--;

		if(s == "end")
			break;
		else if(s == "add")
			ret++;
		else if(s == "for")
		{
			int num;
			cin >> num;

			ret += num * solve(n);
		}

		if(ret >= (1LL << 32))
			overflow = true;
	}

	return ret;
}

int main()
{
	cin >> n;
	while(!overflow && n > 0)
	{
		cin >> command;
		if(command == "add")
			x++;
		else if(command == "for")
		{
			int num;
			cin >> num;

			x += num * solve(n);
		}

		if(x >= (1LL << 32))
			overflow = true;
		n--;
	}

	if(overflow)
		cout << "OVERFLOW!!!\n";
	else
		cout << x << '\n';
}