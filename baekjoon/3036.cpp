#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int n, p, q, r[102];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> r[i];

	p = q = 1;
	for(int i = 1; i < n; i++)
	{
		int g = gcd(r[i], r[i - 1]);
		int a = r[i] / g, b = r[i - 1] / g;
		int np = a * p, nq = b * q;

		g = gcd(np, nq);
		p = np / g, q = nq / g;

		// cout << g << ' ' << a << ' ' << b << ' ' << np << ' ' << nq << '\n';

		cout << q << '/' << p << '\n';
	}
}