#include <iostream>

using namespace std;

int main()
{
	int n, ans;
	cin >> n;

	for(ans = 0; n > 0; n /= 2)
		ans += n % 2;

	cout << ans << '\n';
}