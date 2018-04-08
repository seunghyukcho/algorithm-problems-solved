#include<iostream>

using namespace std;

int a, b;

int main(){
    int ans = 0;

    cin >> a >> b;
    for(int i = a; i <= b; i++)
        ans += i * (i % 2 ? 1 : -1);

    cout << ans << '\n';

    return 0;
}
