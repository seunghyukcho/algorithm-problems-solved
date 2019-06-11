#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int main()
{
	ll a, b;

	cin >> a >> b;
	cout << a * b / gcd(a, b) << '\n';
}