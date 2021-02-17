#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll ansMax = 0, ansMin = 0;
        for(int i = 0; i < n; i++) {
            ansMax += (ll)ceil(a[i] / (double)x);
            ansMin += a[i];
        }

        ansMin = (ll)ceil(ansMin / (double)x);
        cout << ansMin << ' ' << ansMax << '\n';
    }
}
