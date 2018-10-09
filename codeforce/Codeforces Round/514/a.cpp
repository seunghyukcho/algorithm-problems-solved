#include<bits/stdc++.h>

using namespace std;

int n, L, a, t[100002], l[100002];

int main(){
    cin >> n >> L >> a;
    for(int i = 1; i <= n; i++) cin >> t[i] >> l[i];
    t[n + 1] = L;

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += (t[i + 1] - (t[i] + l[i])) / a;
    }

    cout << ans << '\n';
}
