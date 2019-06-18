#include <iostream>

using namespace std;

int n, w, h;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> w >> h;

		if(w == h)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}