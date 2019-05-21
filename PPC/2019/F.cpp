#include <iostream>

using namespace std;

int N, a[40], r[100];

int main()
{
	int start = 0;

	for(int i = 0; i < 36; i++)
		cin >> a[i];
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> r[i + 36];

	for(; start < 36 && a[start] == 0; start++);

	if(start == 36)
	{
		for(int i = 0; i < N; i++)
		{
			if(r[i + 36] == 1)
			{
				cout << "NO\n";
				return 0;
			}
		}

		cout << "YES\n";
		for(int i = 0; i < 36; i++)
			cout << r[i] << ' ';
		cout << '\n';
	}
	else
	{
		for(int i = 35; i >= start; i--)
		{
			int result = 0;
			for(int j = start + 1; j < 36; j++)
				result ^= a[j] * r[i + j - start];
			if(result != r[i + 36 - start])
				r[i] = 1;
			else
				r[i] = 0;
		}

		cout << "YES\n";
		for(int i = 0; i < 36; i++)
			cout << r[i] << ' ';
		cout << '\n';
	}

}