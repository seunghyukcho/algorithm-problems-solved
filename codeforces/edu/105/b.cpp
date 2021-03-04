#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, colored[4];
        cin >> n;
        for(int i = 0; i < 4; i++) cin >> colored[i];

        bool ans = true;
        for(int i = 0; i < 4 && ans; i++) {
            int prev = i, here = (i + 1) % 4, next = (i + 2) % 4, opposite = (i + 3) % 4;
            if(colored[here] <= n - 2) continue;
            else {
                ans = max(colored[here] - n + 2, 0) + max(colored[opposite] - n + 2, 0) <= min(colored[prev], 2) + min(colored[next], 2);
                if(colored[here] == n) ans = ans && colored[prev] > 0 && colored[next] > 0;
            } 
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
