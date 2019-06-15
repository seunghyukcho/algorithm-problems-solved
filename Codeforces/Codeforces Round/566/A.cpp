#include <iostream>
#include <cmath>

using namespace std;

int n;

int main()
{
	cin >> n;

	if(n % 2 == 1)
		cout << 0 << '\n';
	else
		cout << (long long)pow(2, n / 2) << '\n';
}