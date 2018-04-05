#include<iostream>
#include<cmath>

using namespace std;

long long n, ans;

int main(){
    cin >> n;

    n--;
    for(long long i = 1; i <= n; i <<= 1)
        ans += i * ((n - i) / (2 * i) + 1);

    cout << ans << '\n';

    return 0;
}
