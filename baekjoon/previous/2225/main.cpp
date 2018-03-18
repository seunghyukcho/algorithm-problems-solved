#include<iostream>

using namespace std;

int D[202][202];
int N;
int r = 1e9;

int dy(int n, int k){
    if(n < 0 || k <= 0)
        return 0;
    if(n == 0 || k == 1)
        return 1;

    if(D[n][k])
        return D[n][k];

    for(int i = 0; i <= N; i++)
        D[n][k] = ((D[n][k] % r) + (dy(n - i, k - 1) % r)) % r;

    return D[n][k];
}

int main(){
    int k;
    cin >> N >> k;

    cout << dy(N, k) << '\n';

    return 0;
}
