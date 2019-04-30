#include <iostream>
#include <algorithm>

using namespace std;

int cache[52][52][52][52];

int dp(int h1, int h2, int w1, int w2)
{
	int &ret = cache[h1][h2][w1][w2];

	if(ret != 0)
		return ret;

	if(h2 == 0 || w2 == 0)
	{
		if(h1 == w1)
			return ret = 1;

		for(int i = 1; i < w1; i++)
		{
			int result = dp(h1, 0, i, 0) + dp(h1, 0, w1 - i, 0);

			ret = (ret == 0 ? result : min(ret, result));
		}

		for(int i = 1; i < h1; i++)
		{
			int result = dp(i, 0, w1, 0) + dp(h1 - i, 0, w1, 0);

			ret = (ret == 0 ? result : min(ret, result));
		}
	}
	else
	{
		ret = dp(h1, 0, w1 - w2, 0) + dp(h1 - h2, 0, w2, 0);
		ret = min(ret, dp(h2, 0, w1 - w2, 0) + dp(h1 - h2, 0, w1, 0));

		for(int i = 1; i < w1 - w2; i++)
		{
			int result = dp(h1, 0, i, 0) + dp(h1, h2, w1 - i, w2);

			ret = min(ret, result);
		}

		for(int i = 1; i < h1 - h2; i++)
		{
			int result = dp(i, 0, w1, 0) + dp(h1 - i, h2, w1, w2);

			ret = min(ret, result);
		}

		for(int i = 1; i < w2; i++)
		{
			int result = dp(h1, h2, w1 - w2 + i, i) + dp(h1 - h2, 0, w2 - i, 0);

			ret = min(ret, result);
		}

		for(int i = 1; i < h2; i++)
		{
			int result = dp(h1 - h2 + i, i, w1, w2) + dp(h2 - i, 0, w1 - w2, 0);

			ret = min(ret, result);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h1, h2, w1, w2;
	cin >> h1 >> w1 >> h2 >> w2;

	cout << dp(h1, h2, w1, w2) << '\n';
}