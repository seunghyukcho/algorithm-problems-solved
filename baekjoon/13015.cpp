#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			for(int j = 0; j < n; j++)
				cout << '*';
			for(int j = 0; j < (n - i - 1) * 2 - 1; j++)
				cout << ' ';
			for(int j = 0; j < n; j++)
				cout << '*';
		}
		else
		{
			for(int j = 0; j < i; j++)
				cout << ' ';
			cout << '*';
			for(int j = 0; j < n - 2; j++)
				cout << ' ';
			cout << '*';
			for(int j = 0; j < (n - i - 1) * 2 - 1; j++)
				cout << ' ';
			if(i != n - 1)
				cout << '*';
			for(int j = 0; j < n - 2; j++)
				cout << ' ';
			cout << '*';
		}

		cout << '\n';
	}

	for(int i = n - 2; i >= 0; i--)
	{
		if(i == 0)
		{
			for(int j = 0; j < n; j++)
				cout << '*';
			for(int j = 0; j < (n - i - 1) * 2 - 1; j++)
				cout << ' ';
			for(int j = 0; j < n; j++)
				cout << '*';
		}
		else
		{
			for(int j = 0; j < i; j++)
				cout << ' ';
			cout << '*';
			for(int j = 0; j < n - 2; j++)
				cout << ' ';
			cout << '*';
			for(int j = 0; j < (n - i - 1) * 2 - 1; j++)
				cout << ' ';
			if(i != n - 1)
				cout << '*';
			for(int j = 0; j < n - 2; j++)
				cout << ' ';
			cout << '*';
		}

		cout << '\n';
	}
}