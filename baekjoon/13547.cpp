#include <iostream>
#include <algorithm>
#define BUCKET_SIZE 300

using namespace std;

struct Query
{
	int idx, l, r, ans;
} Q[100002];

bool comp1(Query& q1, Query& q2)
{
	return (q1.l / BUCKET_SIZE == q2.l / BUCKET_SIZE) ? 
			q1.r < q2.r : q1.l / BUCKET_SIZE < q2.l / BUCKET_SIZE;
}

bool comp2(Query& q1, Query& q2)
{
	return q1.idx < q2.idx;
}

int m[1000002];
int N, M, A[100002];

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i];
	cin >> M;
	for(int i = 1; i <= M; i++)
	{
		Q[i].idx = i;
		cin >> Q[i].l >> Q[i].r;
	}

	sort(Q + 1, Q + 1 + M, comp1);
	int prevL = 0, prevR = 0, here = 0;

	for(int idx = 1; idx <= M; idx++)
	{
		int hereL = Q[idx].l, hereR = Q[idx].r;

		if(prevR < hereL)
		{
			for(int i = prevL; i <= prevR; i++)
				m[A[i]]--;

			here = 0;
			for(int i = hereL; i <= hereR; i++)
			{
				m[A[i]]++;
				if(m[A[i]] == 1)
					here++;
			}
		}
		else
		{
			for(int i = prevR + 1; i <= hereR; i++)
			{
				m[A[i]]++;
				if(m[A[i]] == 1)
					here++;
			}

			for(int i = prevR; i > hereR; i--)
			{
				m[A[i]]--;
				if(m[A[i]] == 0)
					here--;
			}

			for(int i = prevL; i < hereL; i++)
			{
				m[A[i]]--;
				if(m[A[i]] == 0)
					here--;
			}

			for(int i = prevL - 1; i >= hereL; i--)
			{
				m[A[i]]++;
				if(m[A[i]] == 1)
					here++;
			}
		}

		prevL = hereL, prevR = hereR;
		Q[idx].ans = here;
	}

	sort(Q + 1, Q + 1 + M, comp2);
	for(int i = 1; i <= M; i++)
		cout << Q[i].ans << '\n';
}