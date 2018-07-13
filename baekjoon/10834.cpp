#include<iostream>

using namespace std;

double ans1 = 1;
int ans2, m;

int main(){
    for(cin >> m; m > 0; m--) {
        int a, b, c;
        cin >> a >> b >> c;

        ans2 = (ans2 + c) % 2;
        ans1 *= b / (double)a;
    }

    cout << ans2 << ' ' << (int)ans1 << '\n';

    return 0;
}
