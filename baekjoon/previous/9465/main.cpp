#include<iostream>

using namespace std;

int D[100002][2];
int val[100002][2];
int ans = 0;
int dy(int n, int k){
    if(n < 0)
        return 0;
    if(D[n][k])
        return D[n][k];

    D[n][k] = max(dy(n - 1, (k + 1) % 2), dy(n - 2, (k + 1) % 2)) + val[n][k];
    ans = max(ans, D[n][k]);

    return D[n][k];
}

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int n;
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++){
            cin >> val[i][0];
            D[i][0] = 0;
        }
        for(int i = 0; i < n; i++){
            cin >> val[i][1];
            D[i][1] = 0;
        }

        dy(n - 1, 0);
        dy(n - 1, 1);

        cout << ans << '\n';
    }

    return 0;
}
