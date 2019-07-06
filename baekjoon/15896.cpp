#include <iostream>

using namespace std;

typedef long long ll;

ll ans1, ans2;
int N, A[1000002], B[1000002];
int cntA[30], cntB[30];

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	for(int i = 0; i < N; i++)
		cin >> B[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < 30; j++)
		{
			if((1 << j) & A[i])
				cntA[j]++;
			if((1 << j) & B[i])
				cntB[j]++;
		}

	for(int i = 0; i < 30; i++)
		ans1 += (1LL << i) * cntA[i] * cntB[i];
	cout << ans1 << ' ';

	for(int i = 0; i < 30; i++)
	{
		int cnt1[2] = {0, 0}, cnt2[2] = {0, 0};

		for(int j = 0; j < N; j++)
		{
			if(A[j] % (1 << (j + 1)) < (1 << j))
		}

	}
}