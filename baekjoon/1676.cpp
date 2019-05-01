#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;

	int cntTwos = 0, cntFives = 0;
	for(int i = 2; i <= n; i *= 2)
		cntTwos += n / i;
	for(int i = 5; i <= n; i *= 5)
		cntFives += n / i;

	cout << min(cntTwos, cntFives) << '\n';
}