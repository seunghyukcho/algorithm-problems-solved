#include <iostream>

using namespace std;

typedef long long ll;

int t, n, k, p[102];

bool solve(ll x) {
    ll sum = p[0] + x;

    for(int i = 1; i < n; i++) {
        if(p[i] * 100LL > k * sum) return false;
        sum += p[i];
    }

    return true;
}

int main() {
    for(cin >> t; t > 0; t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> p[i];

        ll start = 0, end = 100e9;
        while(start < end) {
            ll mid = (start + end) / 2;
            if(solve(mid)) end = mid;
            else start = mid + 1;
        }

        cout << start << '\n';
    }
}