#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int n, a[100002], ans;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans = gcd(ans, a[i]);
	}

	cout << ans << '\n';
}