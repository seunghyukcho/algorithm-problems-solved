#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ans = 1;
int train[100002];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int process, x, y;
        cin >> process;
        if(process == 1) {
            cin >> x >> y;
            train[x] |= (1 << (y - 1));
        } else if(process == 2) {
            cin >> x >> y;
            train[x] &= ~(1 << (y - 1));
        } else if(process == 3) {
            cin >> x;
            train[x] <<= 1;
            train[x] &= ~(1 << 20);
        } else {
            cin >> x;
            train[x] >>= 1;
        }
    }

    sort(train + 1, train + n + 1);
    for(int i = 2; i <= n; i++) {
        if(train[i] != train[i - 1]) ans++;
    }

    cout << ans << '\n';

    return 0;
}
