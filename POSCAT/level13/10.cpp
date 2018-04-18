#include<iostream>

using namespace std;

int n, k, ans = 0;

int main(){
    int cnt = 0;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        cnt += n % i ? 0 : 1;
        if(cnt == k){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
