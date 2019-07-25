#include<iostream>

using namespace std;

int t, n, p;

int main(){
    for(cin >> t; t > 0; t--) {
        int ans = 0;
        for(cin >> n; n > 0; n--) {
            cin >> p;
            ans += p ? 1 : 0;
        }

        cout << ans << '\n';
    }
}
