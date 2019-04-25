#include <iostream>

using namespace std;

int t, w, h, n;

int main()
{
	for(cin >> t; t > 0; t--)
	{
		cin >> h >> w >> n;

		int row, col;
		col = (n - 1) / h + 1;
		row = (n - 1) % h + 1;

		cout << row;
		if(col < 10)
			cout << '0';
		cout << col << '\n';
	}
}