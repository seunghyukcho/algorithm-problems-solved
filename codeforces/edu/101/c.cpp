#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        
        vector<pair<int, int> > tmp(n, {-1, -1});
        tmp[0] = {h[0], h[0]};

        bool ans = true;
        for(int i = 1; i < n && ans; i++) {
            pair<int, int> prev = tmp[i - 1];
            pair<int, int> here = {h[i], h[i] + (i == n - 1 ? 0 : k - 1)};

            tmp[i] = {max(here.first, prev.first - k + 1), min(here.second, prev.second + k - 1)};
            if(tmp[i].second < tmp[i].first) ans = false;
        }
        
        if(!ans) cout << "NO\n";
        else cout << "YES\n";
    }
}
