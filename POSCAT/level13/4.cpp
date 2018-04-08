#include<iostream>

using namespace std;

int n;

int main(){
    int ans = 0;

    cin >> n;
    for(int i = 1; i <= n; i++)
        ans += i % 2 ? 0 : i;
    cout << ans << '\n';

    return 0;
}
