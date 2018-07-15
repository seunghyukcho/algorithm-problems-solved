#include<iostream>
#include<cmath>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;

    long long ans = n;
    for(long long i = 1; i <= n - 1; i++) {
        int p = (n - 1) / i;
        int idx1 = ceil((double)n / (p + 1));
        int idx2 = (n - 1) / p;

        //cout << i << ' ' << p << ' ' << idx1 << ' ' << idx2 << '\n';


        ans += (idx2 - idx1 + 1) * (long long)p;
        i = idx2;
    }

    cout << ans << '\n';
}
