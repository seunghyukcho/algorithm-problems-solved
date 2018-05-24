#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, w, t;
int weight[1002], value[1002];
long long D[1000002];

int main(){
    for(cin >> t; t > 0; t--){
        cin >> n >> w;
        for(int i = 0; i < n; i++)
            cin >> weight[i];
        for(int i = 0; i < n; i++)
            cin >> value[i];
        for(int i = 0; i <= w; i++)
            D[i] = -1;
        D[0] = 0;

        long long ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = w; j >= 0; j--){
                if(D[j] != -1){
                    if(j + weight[i] <= w){
                        D[j + weight[i]] = max(D[j + weight[i]], D[j] + value[i]);
                        ans = max(ans, D[j + weight[i]]);
                    }
                }
            }

        cout << ans << '\n';
    }

    return 0;
}
