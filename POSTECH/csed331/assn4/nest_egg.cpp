#include<iostream>

using namespace std;

int t, coins[4] = {50000, 10000, 5000, 1000};
long long n;

int main(){
    for(cin >> t; t > 0; t--){
        long long ans = 0;

        cin >> n;
        for(int i = 0; i < 4; i++){
            ans += n / coins[i];
            n %= coins[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
