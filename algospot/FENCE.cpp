#include<iostream>
#include<algorithm>

using namespace std;

int c, n, h[20002], st[20002];

int main(){
	for(cin >> c; c > 0; c--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> h[i];

		int top = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			while(top > 0 && h[st[top - 1]] > h[i]) {
				int height = h[st[top - 1]];
				int right = i;
				int left = (top == 1 ? 0 : st[top - 2] + 1);

				ans = max(ans, height * (right - left));
				top--;
			}

			st[top++] = i;
		}

		for(int i = 0; i < top; i++) {
			int height = h[st[i]];
			int right = st[top - 1];
			int left = (i == 0 ? 0 : st[i - 1] + 1);

			ans = max(ans, height * (right - left + 1));
		}

		cout << ans << '\n';
	}

	return 0;
}
				

