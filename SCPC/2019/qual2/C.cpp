#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Line
{
	int pos, w, h;
};

int T, A, B, L, S, E;
Line upper[100002], lower[100002];

int main()
{
	upper[0] = {0, 0, 0};
	lower[0] = {0, 0, 0};

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		ll ans = 0;

		cout << "Case #" << t << '\n';
		cin >> L >> S >> E;
		cin >> A;
		for(int i = 1; i <= A; i++)
		{
			cin >> upper[i].w >> upper[i].h;
			upper[i].pos = upper[i - 1].pos + upper[i - 1].w;
		}

		cin >> B;
		for(int i = 1; i <= B; i++)
		{
			cin >> lower[i].w >> lower[i].h;
			lower[i].pos = lower[i - 1].pos + lower[i - 1].w;
		}

		int pos1 = 1, pos2 = 1, herex = 0, herey = S, hereidx = 1;
		for(int i = 2; i <= A; i++)
		{
			if(upper[i].h < herey)
			{
				ll width = upper[i].pos - herex;
				ll result = (herey - upper[i].h) * width;

				while(lower[pos2].pos + lower[pos2].w <= upper[i].pos)
				{
					if(lower[pos2].h > upper[i].h)
					{
						if(lower[pos2].h > herey)
						{
							result += (lower[pos2].h - herey) * width;
							herey = lower[pos2].h;
						}
							
						result -= (lower[pos2].h - upper[i].h) * (ll)lower[pos2].w;
						herex = lower[pos2].pos + lower[pos2].w;
					}

					pos2++;
				}

				ans += result
				herey = upper[i].h;
				hereidx = i;
			}
			else
			{
				while(lower[pos2].pos + lower[pos2].w <= upper[i].pos)
				{
					if(herey < lower[pos2].h)
					{
						ans += (lower[pos2].h - herey) * (ll)(lower[pos2].pos - herex);
						for(int pos3 = i - 1; pos3 > 0 && )
					}

					pos2++;
				}
			}
		}
	}
}