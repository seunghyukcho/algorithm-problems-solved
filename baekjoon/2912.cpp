#include <iostream>
#include <algorithm>
#define BUCKET_SIZE 170

using namespace std;

struct Query
{
	int idx, l, r;
	int ans[2];
} Q[10002];

bool comp1(Query q1, Query q2)
{
	return (q1.l / BUCKET_SIZE == q2.l / BUCKET_SIZE) ?
			q1.r < q2.r : q1.l / BUCKET_SIZE < q2.l / BUCKET_SIZE;
}

bool comp2(Query q1, Query q2)
{
	return q1.idx < q2.idx;
}

int N, M, C, hat[300002], cnt[10002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for(int i = 1; i <= N; i++)
		cin >> hat[i];
	cin >> M;
	for(int i = 1; i <= M; i++)
	{
		Q[i].idx = i;
		cin >> Q[i].l >> Q[i].r;
	}

	sort(Q + 1, Q + 1 + M, comp1);

	int prevL = 0, prevR = 0;
	for(int idx = 1; idx <= M; idx++)
	{
		int hereL = Q[idx].l, hereR = Q[idx].r;
		int sz = hereR - hereL + 1;

		for(int i = prevL; i < hereL; i++)
			cnt[hat[i]]--;
		for(int i = prevL - 1; i >= hereL; i--)
			cnt[hat[i]]++;
		for(int i = prevR + 1; i <= hereR; i++)
			cnt[hat[i]]++;
		for(int i = prevR; i > hereR; i--)
			cnt[hat[i]]--;
		prevL = hereL, prevR = hereR;

		Q[idx].ans[0] = Q[idx].ans[1] = 0;
		for(int i = 1; i <= C; i++)
		{
			if(cnt[i] > sz / 2)
			{
				Q[idx].ans[0] = 1;
				Q[idx].ans[1] = i;
			}
		}
		cout << '\n';
	}

	sort(Q + 1, Q + 1 + M, comp2);
	for(int i = 1; i <= M; i++)
	{
		if(Q[i].ans[0] == 0)
			cout << "no\n";
		else
			cout << "yes " << Q[i].ans[1] << '\n';
	}
}