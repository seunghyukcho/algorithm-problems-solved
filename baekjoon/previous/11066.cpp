#include<iostream>

using namespace std;

int num[502], sum[502], d[502][502];

int dy(int i, int j){
    int ret = 1e9;

    if(d[i][j])return d[i][j];
    if(i == j)
        return 0;
    if(i + 1 == j)
        return d[i][j] = sum[j] - sum[i-1];

    for(int k = i; k < j; k++)
        ret = min(ret, dy(i, k) + dy(k + 1, j));

    ret += sum[j] - sum[i - 1];
    return d[i][j] = ret;
}

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int k;
        cin >> k;

        for(int i = 1; i <= k; i++){
            cin >> num[i];
            sum[i] = num[i] + sum[i - 1];
        }
        for(int i = 1; i <= k; i++){
            for(int j = i; j <= k; j++)
                d[i][j] = 0;
        }

        cout << dy(1, k) << '\n';

    }

    return 0;
}

