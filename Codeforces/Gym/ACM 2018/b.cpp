#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n;
long long x;

int main(){
    for(cin >> t; t > 0; t--){
        cin >> x >> n;

        vector<long long> ans(n + 1);

        if(n == 1){
            cout << x << '\n';
            continue;
        }

        for(int i = 1; x && i <= n; i++){
            ans[i] = 1;
            x--;
        }

        if(x){
            long long sum = x / (2 * (n - 1));
            x = x % (2 * (n - 1));

            ans[1] += sum;
            ans[n] += sum;
            for(int i = 2; i < n; i++)
                ans[i] += sum * 2;

            int start = n - 1;
            for(int i = n - 1; x && i >= 1; i--){
                ans[i]++;
                x--;
            }

            for(int i = 2; x && i <= n; i++){
                ans[i]++;
                x--;
            }
        }

        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
