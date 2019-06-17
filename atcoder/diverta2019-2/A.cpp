#include <iostream>

using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	if(k == 1)
		cout << "0\n";
	else
		cout << n - k << '\n';
}