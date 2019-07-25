#include<iostream>

using namespace std;

int main() {
	int n, c, ans;
	for(cin >> c; c > 0; c--) {
		long long d[101][101];

		cin >> n;
		ans = 0;
		for(int i = 0; i <= n; i++) d[i][0] = 1;


		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				d[i][j] = (i == j ? 1 : 0);
				for(int k = 1; k <= i - j; k++) {
					d[i][j] += (j + k - 1) * d[i - j][k];
					d[i][j] %= 10000000;
				}

				if(i == n) {
					ans += d[i][j];
					ans %= 10000000;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

