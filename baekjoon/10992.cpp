#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;

	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = 0; j < n - i; j++)
			cout << ' ';
		cout << '*';
		for(int j = 0; j < 2 * i - 3; j++)
			cout << ' ';
		cout << (i == 1 ? "\n" : "*\n");
	}

	for(int i = 0; i < 2 * n - 1; i++)
		cout << '*';
	cout << '\n';
}