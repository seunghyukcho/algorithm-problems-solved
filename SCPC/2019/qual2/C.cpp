#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

struct Line
{
	int pos, dir, w, h;
} L[200010];

bool comp(Line &l1, Line &l2)
{
	return l1.pos + l1.w < l2.pos + l2.w;
}

int T, A, B, l, S, E;
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
		cin >> l >> S >> E;
		cin >> A;
		for(int i = 1; i <= A; i++)
		{
			cin >> upper[i].w >> upper[i].h;
			upper[i].pos = upper[i - 1].pos + upper[i - 1].w;
			upper[i].dir = 1;
			L[i] = upper[i];
		}

		cin >> B;
		for(int i = 1; i <= B; i++)
		{
			cin >> lower[i].w >> lower[i].h;
			lower[i].pos = lower[i - 1].pos + lower[i - 1].w;
			lower[i].dir = -1;
			L[A + i] = lower[i];
		}

		sort(L + 1, L + A + B + 1, comp);

		int herex = 0, herey = S;
		deque<Line> u, d;
		for(int i = 1; i <= A + B; i++)
		{
			Line here = L[i];
			if(here.dir == 1)
			{
				if(herey > here.h)
				{
					while(!d.empty() && d.front().h >= here.h)
					{
						Line next = d.front(); d.pop_front();

						ans += (next.w + next.pos - herex) * (ll)(herey - next.h);
						herex = next.w + next.pos;
					}

					ans += (here.pos - herex) * (ll)(herey - here.h);
					herey = here.h;
					u.clear();
					u.push_back(here);
				}
				else
				{
					while(!u.empty() && u.back().h > here.h)
						u.pop_back();
					u.push_back(here);
				}
			}
			else
			{
				if(herey < here.h)
				{
					while(!u.empty() && u.front().h <= here.h)
					{
						Line next = u.front(); u.pop_front();

						ans += (next.w + next.pos - herex) * (ll)(next.h - herey);
						herex = next.w + next.pos;
					}

					ans += (here.pos - herex) * (ll)(here.h - herey);
					herey = here.h;
					d.clear();
					d.push_back(here);
				}
				else
				{
					while(!d.empty() && d.back().h < here.h)
						d.pop_back();
					d.push_back(here);
				}
			}

			// cout << herex << ' ' << herey << ' ' << ans << '\n';
		}

		if(herey < E)
		{
			while(!u.empty() && u.front().h <= E)
			{
				Line next = u.front(); u.pop_front();

				ans += (next.w + next.pos - herex) * (ll)(next.h - herey);
				herex = next.w + next.pos;
			}

			ans += (l - herex) * (ll)(E - herey);
		}
		else if(herey > E)
		{
			while(!d.empty() && d.front().h >= E)
			{
				Line next = d.front(); d.pop_front();

				ans += (next.w + next.pos - herex) * (ll)(herey - next.h);
				herex = next.w + next.pos;
			}

			ans += (l - herex) * (ll)(herey - E);
		}
		cout << ans << '\n';
	}
		
}