#include <iostream>

using namespace std;

int t, m, n, x, y;

int main()
{
	for(cin >> t; t > 0; t--)
	{
		cin >> m >> n >> x >> y;

		int i;
		for(i = 0; m * i + x <= m * n; i++)
		{
			int newN = m * i + x;

			if((newN - 1) % n + 1 == y)
				break;
		}

		cout << (m * i + x > m * n ? -1 : m * i + x) << '\n';
	}
}