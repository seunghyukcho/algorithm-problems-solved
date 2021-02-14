#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = k + 1;

    vector<int> diff(n + 1);
    for(int i = 1; i <= n; i++) diff[i] = diff[i - 1] + a[i + 1] - a[i - 1] - 2;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        if(l == r) cout << k - 1 << '\n';
        else cout << diff[r - 1] - diff[l] + a[l + 1] - 2 + k - a[r - 1] - 1 << '\n';
        
    }
}
