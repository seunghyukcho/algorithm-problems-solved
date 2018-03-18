#include<iostream>

using namespace std;

int D[102][10];
int r = 1e9;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++)
        D[0][i] = 1;

    for(int i = 1; i < n; i++){
        for(int k = 0; k < 10; k++){
            if(k - 1 >= 0)
                D[i][k] = ((D[i][k] % r) + (D[i - 1][k - 1] % r)) % r;
            if(k + 1 < 10)
                D[i][k] = ((D[i][k] % r) + (D[i - 1][k + 1] % r)) % r;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans = ((D[n - 1][i] % r) + (ans % r)) % r;

    cout << ans << '\n';

    return 0;
}
