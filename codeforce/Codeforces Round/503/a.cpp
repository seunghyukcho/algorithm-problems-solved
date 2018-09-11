#include<iostream>
#include<cmath>

using namespace std;

int n, h, a, b, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h >> a >> b;
    for(cin >> k; k > 0; k--) {
        int ta, tb, fa, fb;
        cin >> ta >> fa >> tb >> fb;

        if(ta == tb) cout << abs(fa - fb) << '\n';
        else if(fa >= a && fa <= b) cout << abs(ta - tb) + abs(fa - fb) << '\n';
        else cout << min(abs(a - fa) + abs(a - fb), abs(b - fa) + abs(b - fb)) + abs(ta - tb) << '\n';
    }

    return 0;
}
