#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        cin >> n;
        vector<int> r(n);
        for(int i = 0; i < n; i++) cin >> r[i];
        cin >> m;
        vector<int> b(m);
        for(int i = 0; i < m; i++) cin >> b[i];

        int ans = 0, s1 = 0, s2 = 0;
        for(int i = 0; i < m; i++) {
            s2 += b[i];
            ans = max(ans, s2);
        }

        for(int i = 0; i < n; i++) {
            s1 += r[i];
            s2 = 0;
            ans = max(ans, s1);
            for(int i = 0; i < m; i++) {
                s2 += b[i];
                ans = max(ans, s1 + s2);
            }
        }

        cout << ans << '\n';
    }
}
