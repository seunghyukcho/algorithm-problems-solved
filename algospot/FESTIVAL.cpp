#include<iostream>

using namespace std;

int main() {
	int c, n, l;
	for(cin >> c; c > 0; c--) {
		int sum[1002];
		sum[0] = 0;
		
		cin >> n >> l;
		for(int i = 1; i <= n; i++) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}

		double ans = 100;
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++) {
				if(j - i + 1 < l) 
					continue;

				double avg = (sum[j] - sum[i - 1]) / ((double)(j - i + 1));
				ans = ans > avg ? avg : ans;
			}

		printf("%.7lf\n", ans);
	}

	return 0;
}
