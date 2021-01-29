#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int t, n;
ll d[200002];

int main() {
    for(cin >> t; t > 0; t--) {
        bool ans = true;
        ll sum = 0, prev = 0;

        cin >> n;
        for(int i = 0; i < 2 * n; i++) cin >> d[i];
        sort(d, d + 2 * n);

        for(int i = n - 1; ans && i >= 0; i--) {
            if(d[2 * i] != d[2 * i + 1] || d[2 * i] % 2 == 1) ans = false;
            else {
                ll a = d[2 * i] / 2 - sum;
                if(a % (i + 1) != 0 || a <= 0) ans = false;
                else if(prev == (a / (i + 1))) ans = false;
                else {
                    sum += a / (i + 1);
                    prev = a / (i + 1);
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}