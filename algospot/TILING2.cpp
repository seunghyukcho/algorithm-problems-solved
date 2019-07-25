#include<iostream>

using namespace std;

int main() {
	int c, n;
	for(cin >> c; c > 0; c--) {
		long long d[102];
			
		cin >> n;
		d[0] = 1;
		for(int i = 1; i <= n; i++) d[i] = 0;
		for(int i = 0; i <= n - 1; i++) {
			d[i + 1] += d[i];
			d[i + 2] += d[i];

			d[i + 1] %= 1000000007;
			d[i + 2] %= 1000000007;
		}

		cout << d[n] << '\n';
	}

	return 0;
}

