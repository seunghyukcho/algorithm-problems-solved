#include<iostream>

using namespace std;

long long n;
int q, hx, hy;

long long view1(int x, int y) {
    long long ans = 0;

    if(n % 2 == 0) ans += (n / 2) * (x - 1);
    else ans += n * ((x - 1) / 2) + (((x - 1) % 2) ? n / 2 + n % 2 : 0);

    ans += (long long)y / 2 + y % 2;
    return ans;
}

long long view2(int x, int y) {
    long long ans = 0;

    if(n % 2 == 0) ans += (n / 2) * (x - 1);
    else ans += n * ((x - 1) / 2) + (((x - 1) % 2) ? n / 2 : 0);

    ans += y / 2 + y % 2;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(; q > 0; q--) {
        cin >> hx >> hy;

        long long ans = 0;

        if(hx % 2 == hy % 2) {
            cout << view1(hx, hy) << '\n';
        } else {
            long long cv = n * n / 2 + n % 2;

            cout << view2(hx, hy) + cv << '\n';
        }
    }

    return 0;
}
