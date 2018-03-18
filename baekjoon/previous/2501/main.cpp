#include<iostream>

using namespace std;

int main(){
    int i, n, k;
    cin >> n >> k;
    int cnt = 0;
    for(i = 1; i <= n; i++){
        if(n % i == 0)cnt++;
        if(cnt == k)break;
    }
    if(cnt == k)cout << i << '\n';
    else cout << 0 << '\n';

    return 0;
}
