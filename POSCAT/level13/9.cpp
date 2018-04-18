#include<iostream>
#include<algorithm>

using namespace std;

int a, b, c, ans;

int main(){
    cin >> a >> b >> c;

    for(int i = min(a, b); i <= max(a, b); i++)
        ans += i % c ? 0 : 1;

    cout << ans << '\n';

    return 0;
}
