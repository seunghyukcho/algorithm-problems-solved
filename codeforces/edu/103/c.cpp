#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);

        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<ll> dp(n, 0);
        ll ans = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] != b[i]) dp[i] = max((ll)abs(b[i] - a[i]), dp[i - 1] - abs(b[i] - a[i]));
            dp[i] += c[i] + 1;
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }
}