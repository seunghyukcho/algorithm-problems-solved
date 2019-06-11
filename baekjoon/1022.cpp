#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int ans(int x, int y)
{
	int len = 2 * max(abs(x), abs(y)) + 1;

	if(len == 1)
		return 1;

	if(x == len / 2)
		return pow(len, 2) + y - len / 2;
	else if(y == -len / 2)
		return pow(len - 1, 2) + x + len / 2 + 1;
	else if(x == -len / 2)
		return pow(len - 1, 2) - y - len / 2 + 1;
	else
		return pow(len - 2, 2) - x + len / 2;
}

int digit(int num)
{
	int ret = 0;

	while(num > 0)
	{
		num /= 10;
		ret++;
	}

	return ret;
}

int main()
{
	int r1, r2, c1, c2, maxDigit = 1;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	
	for(int i = r1; i <= r2; i++)
		for(int j = c1; j <= c2; j++)
			maxDigit = max(maxDigit, digit(ans(i, j)));
	

	for(int i = r1; i <= r2; i++)
	{
		for(int j = c1; j <= c2; j++)
			printf("%*d ", maxDigit, ans(i, j));
		cout << '\n';
	}
}