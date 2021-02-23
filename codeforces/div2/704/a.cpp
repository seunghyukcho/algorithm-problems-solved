#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

ll conv(ll num, ll p) {
    return (ll)ceil(p / (double)num) * num - p;
}

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;

        cout << min(conv(a, p), min(conv(b, p), conv(c, p))) << '\n';
    }
}
