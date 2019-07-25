#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Pole
{
	ll x, h;
} P[8000002];

bool comp(Pole& p1, Pole& p2)
{
	return p1.x < p2.x;
}

int isOccupied(Pole& p1, Pole& p2)
{
	if(p2.x < p1.x + p1.h && p2.h <= p1.h - p2.x + p1.x)
		return 1;
	else if(p1.x > p2.x - p1.h && p1.h <= p1.h - p2.x + p1.x)
		return -1;
	else
		return 0;
}

int T, N, X1, X2, AX, BX, CX, AH, BH, CH;
vector<Pole> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": \n";
		ans.clear();
		cin >> N;
		cin >> X1 >> AX >> BX >> CX;
		cin >> X2 >> AH >> BH >> CH;

		P[0] = { X1, X2 };
		for(int i = 1; i < N; i++)
		{
			P[i].x = ((ll)AX * P[i - 1].x + BX) % CX + 1;
			P[i].h = ((ll)AH * P[i - 1].h + BH) % CH + 1;
		}

		sort(P, P + N, comp);
		for(int i = 0; i < N; i++)
		{
			while(!ans.empty() && isOccupied(ans.back(), P[i]) == -1)
				ans.pop_back();
			if(!ans.empty() && isOccupied(ans.back(), P[i]) == 1)
				continue;
			ans.push_back(P[i]);
		}

		

	}

}