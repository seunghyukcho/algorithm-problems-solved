#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n + 1, 0);
        for(int i = 0; i < n; i++) cin >> h[i];

        int ans;
        while(k > 0) {
            for(ans = 0; ans < n && h[ans] >= h[ans + 1]; ans++);

            if(ans == n) break;

            int diff;
            if(ans == 0) diff = h[ans + 1] - h[ans];
            else diff = min(h[ans + 1] - h[ans], h[ans - 1] - h[ans] + 1);

            h[ans] += diff;
            k -= diff;
        }

        cout << (ans == n ? -1 : ans + 1) << '\n';
    }
}