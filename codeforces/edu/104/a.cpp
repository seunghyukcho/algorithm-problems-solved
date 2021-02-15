#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        int ans = 0;
        for(; ans < n - 1 && a[ans] == a[ans + 1]; ans++);

        cout << n - ans - 1 << '\n';
    }
}
