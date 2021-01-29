#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, cnt[102], ans;

int main() {
    for(cin >> t; t > 0; t--) {
        cin >> n;
        memset(cnt, 0, sizeof(int) * (n + 1));
        ans = 0;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            cnt[num]++;
            ans = max(ans, cnt[num]);
        }

        cout << ans << '\n';
    }
}