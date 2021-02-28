#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) cnt++;
    }

    for(; q > 0; q--) {
        int t, x;
        cin >> t >> x;

        if(t == 1) {
            x--;
            a[x] = 1 - a[x];
            if(a[x] == 1) cnt++;
            else cnt--;
        }
        else {
            cout << (cnt >= x ? 1 : 0) << '\n';
        }
    }

    return 0;
}
