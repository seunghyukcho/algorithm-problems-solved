#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	ll a, b, ans;

	cin >> a >> b;
	ans = gcd(a, b);

	for(int i = 0; i < ans; i++)
		cout << 1;
	cout << '\n';
}