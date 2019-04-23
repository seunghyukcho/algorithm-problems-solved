#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (n - 1) / 2 + 1; j++)
			cout << "* ";
		cout << '\n';
		if(n != 1)
		{
			for(int j = 0; j < n / 2; j++)
				cout << " *";
			cout << '\n';
		}
	}
}