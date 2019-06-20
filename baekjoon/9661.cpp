#include <iostream>

using namespace std;

typedef long long ll;

bool func(ll n)
{
	if(n == 0)
		return false;
	for(ll i = 0; (1 << (2 * i)) <= n; i++)
	{
		if(!func(n - (1 << (2 * i))))
			return true;
	}

	return false;
}

int main()
{
	ll n;
	
	cin >> n;

	ll ret = n % 5;
	if(ret == 1 || ret == 3 || ret == 4)
		cout << "SK\n";
	else
		cout << "CY\n";

}