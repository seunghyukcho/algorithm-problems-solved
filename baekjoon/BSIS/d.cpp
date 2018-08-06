#include<iostream>

using namespace std;

int check[1000001], ans, n;

int main(){
    ios::sync_with_stdio(false);

    for(cin >> n; n > 0; n--) {
        int num;
        cin >> num;

        check[num] = 1 + check[num - 1];
        ans = max(ans, check[num]);
    }

    cout << ans << '\n';

    return 0;
}
