#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int x, y;
        cin >> x >> y;

        ll ans = 0;
        for(int k = 1; k * k <= x; k++) {
            int end = min(y, (x - k) / k);
            if(end >= k + 1) ans += end - k;
        }

        cout << ans << '\n';
    }
}
