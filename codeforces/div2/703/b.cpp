#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

        if(n % 2 == 1) cout << 1 << '\n';
        else {
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            int xrange = x[n / 2] - x[n / 2 - 1] + 1;
            int yrange = y[n / 2] - y[n / 2 - 1] + 1;

            cout << (long long)xrange * yrange << '\n';
        }
    }
}
