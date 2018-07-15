#include<iostream>

using namespace std;

int main(){
    int n, ans = 0, m, c[1002], a[1002];
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> a[i];

    int here = 0;
    for(int i = 0; i < n && here < m; i++) {
        if(a[here] >= c[i]) {
            ans++;
            here++;
        }
    }

    cout << ans << '\n';

    return 0;

}
