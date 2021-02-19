#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        ll sum = 0;
        bool ans = true;
        for(int i = 0; i < n; i++) {
            cin >> h[i];
            sum += h[i];

            if(sum < i * (i + 1) / 2) ans = false;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
