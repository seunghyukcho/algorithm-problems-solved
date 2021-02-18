#include <iostream>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n, k;
        cin >> n >> k;

        int m = n - k;
        for(int i = 1; i < k - m; i++) cout << i << ' ';
        for(int i = k; i >= k - m; i--) cout << i << ' ';
        cout << '\n';
    }
}
