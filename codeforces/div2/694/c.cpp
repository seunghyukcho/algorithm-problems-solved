#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    for(cin >> t; t > 0; t--) {
        int n, m;
        cin >> n >> m;

        vector<int> k(n), c(m);
        for(int i = 0; i < n; i++) cin >> k[i];
        for(int i = 0; i < m; i++) cin >> c[i];

        ll ans = 0;
        int used = 0;
        sort(k.begin(), k.end(), comp);
        for(int i = 0; i < n; i++) {
            if(used < k[i]) ans += c[used++];
            else ans += c[k[i] - 1];
        }

        cout << ans << '\n';
    }
}
