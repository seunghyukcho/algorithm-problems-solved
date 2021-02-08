#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int A, n;
        ll B;
        cin >> A >> B >> n;

        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        for(int i = 0; i < n; i++) B -= (ll)a[i] * (b[i] / A + (b[i] % A != 0));
        
        bool ans = false;
        for(int i = 0; i < n && !ans; i++) {
            if(B + a[i] > 0) {
                ans = true;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
