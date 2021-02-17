#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;
        vector<int> cnt(n);
        int minCount = 1e9, minIdx = 0;
        for(int i = 0; i < n; i++) {
            for(int tmp = a[i]; tmp > 0 && tmp % x == 0; tmp /= x) cnt[i]++;
            if(minCount > cnt[i]) {
                minCount = cnt[i];
                minIdx = i;
            }
        }

        for(int i = 0; i < n; i++) ans += (ll)a[i] * (i < minIdx ? minCount + 2 : minCount + 1);
        cout << ans << '\n';    
    }
}
