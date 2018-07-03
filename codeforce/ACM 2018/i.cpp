#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long t, x, n;

    for(cin >> t; t > 0; t--){
        cin >> x >> n;

        vector<long long> ans(n + 1);

        if(x / n == 0){
            cout << -1 << '\n';
            continue;
        }
            
        for(int i = 1; i <= n; i++)
            ans[i] = x / n;
        x %= n;
        for(int i = n; x && i > 0; i--){
            ans[i] += 1;
            x--;
        }

        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
