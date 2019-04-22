#include <iostream>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = n; i >= 1; i--)
	{
		for(int j = 1; j <= n - i; j++)
			cout << " ";
		for(int j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << '\n';
	}
}