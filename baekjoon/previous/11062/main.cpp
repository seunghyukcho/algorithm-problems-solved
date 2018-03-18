#include<iostream>

using namespace std;

int n, num[1002], sum[1002], d[1002][1002];

int dy(int i, int j){
    int ret = 0;

    if(d[i][j])
        return d[i][j];
    if(i == j)
        return d[i][j] = num[i];

    ret = min(dy(i+1, j), dy(i, j-1));
    ret = sum[j] - sum[i-1] - ret;

    return d[i][j] = ret;
}

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            sum[i] = num[i] + sum[i-1];
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                d[i][j] = 0;
        }
        
        cout << dy(1, n) << '\n';

    }

    return 0;
}
