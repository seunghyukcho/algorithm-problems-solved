#include<iostream>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    while(n >= 2 && m >= 1 && n + m >= k + 3){
        ans += 1;
        n -= 2;
        m -= 1;
    }

    cout << ans << '\n';

    return 0;
}
