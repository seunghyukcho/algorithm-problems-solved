#include <iostream>
#include <cmath>

using namespace std;

int cntPos, cntNeg;
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if(num > 0)
			cntPos++;
		else if(num < 0)
			cntNeg++;
	}

	if(cntPos >= ceil(n / 2.0))
		cout << 1 << '\n';
	else if(cntNeg >= ceil(n / 2.0))
		cout << -1 << '\n';
	else
		cout << 0 << '\n';
}