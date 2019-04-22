#include <iostream>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
			cout << '*';
		cout << '\n';
	}

	for(int i = n - 1; i >= 1; i--)
	{
		for(int j = 0; j < i; j++)
			cout << '*';
		cout << '\n';
	}
}