#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

int main()
{
	cin >> n >> m >> k;

	cout << (n <= min(m, k) ? "YES" : "NO") << '\n';
}