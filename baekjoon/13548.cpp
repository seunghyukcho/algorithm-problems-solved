#include <iostream>
#include <algorithm>
#define BUCKET_SIZE 170

using namespace std;

struct Query
{
	int idx, l, r, ans;
} Q[100002];

bool comp1(Query q1, Query q2)
{
	return (q1.l / BUCKET_SIZE == q2.l / BUCKET_SIZE) ?
			q1.r < q2.r : q1.l / BUCKET_SIZE < q2.l / BUCKET_SIZE;
}

bool comp2(Query q1, Query q2)
{
	return q1.idx < q2.idx;
}

int N, M, A[100002];
int cnt[100002], cnt2[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for(int i = 1; i <= M; i++)
	{
		Q[i].idx = i;
		Q[i].ans = 0;
		cin >> Q[i].l >> Q[i].r;
	}

	sort(Q + 1, Q + 1 + M, comp1);

	int prevL = 0, prevR = 0, ans = 0;
	for(int idx = 1; idx <= M; idx++)
	{
		int hereL = Q[idx].l, hereR = Q[idx].r;

		for(int i = prevL; i < hereL; i++)
		{
			if(cnt2[cnt[A[i]]] == 1 && cnt[A[i]] == ans)
				ans--;

			cnt2[cnt[A[i]]]--;
			cnt[A[i]]--;
			cnt2[cnt[A[i]]]++;
		}

		for(int i = prevL - 1; i >= hereL; i--)
		{
			cnt2[cnt[A[i]]]--;
			cnt[A[i]]++;
			cnt2[cnt[A[i]]]++;

			ans = max(ans, cnt[A[i]]);
		}

		for(int i = prevR + 1; i <= hereR; i++)
		{
			cnt2[cnt[A[i]]]--;
			cnt[A[i]]++;
			cnt2[cnt[A[i]]]++;

			ans = max(ans, cnt[A[i]]);
		}

		for(int i = prevR; i > hereR; i--)
		{
			if(cnt2[cnt[A[i]]] == 1 && cnt[A[i]] == ans)
				ans--;

			cnt2[cnt[A[i]]]--;
			cnt[A[i]]--;
			cnt2[cnt[A[i]]]++;
		}

		prevL = hereL, prevR = hereR;
		Q[idx].ans = ans;
	}

	sort(Q + 1, Q + 1 + M, comp2);

	for(int i = 1; i <= M; i++)
		cout << Q[i].ans << '\n';

}