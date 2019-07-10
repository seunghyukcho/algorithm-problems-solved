#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cout << fixed << setprecision(2);

	for(cin >> n; n > 0; n--)
	{
		double price;
		cin >> price;
		
		cout << price * 1.15 << '\n';
	}
}