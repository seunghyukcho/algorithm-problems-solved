#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ll x, y, z;

	cin >> x >> y >> z;

	if(x % z > y % z)
		swap(x, y);

	if(y % z + x % z >= z)
		cout << (x / z + y / z + 1) << ' ' << (z - y % z) << '\n';
	else
		cout << (x / z + y / z) << ' ' << 0 << '\n';

}