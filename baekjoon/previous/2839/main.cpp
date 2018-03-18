#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    int k = 1;
    while(5 * k < n)k++;
    while(n >= 3*k){
        if((n-3*k)%2 == 0 && (5*k-n)%2 == 0){
            ans = k;
            break;
        }
        k++;
    }

    if(ans != 0)cout << ans <<'\n';
    else cout << -1 << '\n';

    return 0;
}
