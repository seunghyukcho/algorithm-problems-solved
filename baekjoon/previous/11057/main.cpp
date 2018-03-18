#include<iostream>

using namespace std;

int D[1002][10];
int r = 10007;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 10; i++)
        D[0][i] = 1;

    for(int i = 1; i < n; i++){
        for(int k = 0; k < 10; k++){
            if(k == 0)
                D[i][k] = ((D[i][k] % r) + (D[i - 1][k] % r)) % r;
            else
                D[i][k] = ((D[i][k] % r) + (D[i][k - 1] % r) + (D[i - 1][k] % r)) % r;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans = ((ans % r) + (D[n - 1][i] % r)) % r;
    
    cout << ans << '\n';

    return 0;
}
