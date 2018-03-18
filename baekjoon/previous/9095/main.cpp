#include<iostream>

using namespace std;

int D[20];

int dy(int n){
    if(n < 0)
        return 0;

    if(D[n] != 0)
        return D[n];
    else
        return D[n] = dy(n - 1) + dy(n - 2) + dy(n - 3);
}

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int n;
        cin >> n;

        D[0] = 1;
        for(int i = 1; i <= n; i++)
            D[i] = 0;

        cout << dy(n) << '\n';
    }

    return 0;
}

