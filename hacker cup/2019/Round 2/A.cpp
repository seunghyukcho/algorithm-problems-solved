#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T;

int main()
{
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";

		bool ans = true;
		int N, M, K, A, B, x[2], y[2];
		cin >> N >> M >> K >> A >> B;
		for(int i = 0; i < K; i++)
			cin >> x[i] >> y[i];
		if(K == 1)
			ans = false;
		else
		{
			for(int i = 0; i < 2; i++)
			{
				int diffx = abs(A - x[i]), diffy = abs(B - y[i]);
				if(diffx % 2 == 0 && diffy % 2 == 1)
					ans = false;
				else if(diffx % 2 == 1 && diffy % 2 == 0)
					ans = false;
			}
		}

		cout << (ans ? "Y" : "N") << '\n';
	}
}