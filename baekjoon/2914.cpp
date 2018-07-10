#include<iostream>
#include<cmath>

using namespace std;

int a, i;

int main(){
    cin >> a >> i;

    int ans;
    for(ans = a * i; ceil((double)ans / a) == i; ans--) {}

    cout << ans + 1 << '\n';

    return 0;
}
