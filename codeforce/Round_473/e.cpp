#include<iostream>

using namespace std;

int main(){
    long long n;
    long long ans = 0;

    cin >> n;
    n--;

    ans += (n / 2) + n % 2;
    ans += (n / 2) * 2;
    for(int k = 2; n / (1 << k) > 0; k++){
        ans += (1 << (k - 1)) * (n / (1 << k));
    }

    cout << ans << '\n';

    return 0;
}
