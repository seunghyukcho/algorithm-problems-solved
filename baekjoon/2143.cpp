#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int t, n, m;
int asum[1002], bsum[1002];
map<int, int> b;

int main(){
    long long ans = 0;

    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        cin >> asum[i];
        asum[i] += asum[i - 1];
    }

    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> bsum[i];
        bsum[i] += bsum[i - 1];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < i; j++){
            int sum = bsum[i] - bsum[j];
            if(!b[sum]) b[sum] = 0;
            b[sum]++;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int sum = asum[i] - asum[j];

            if(b.count(t - sum))
                ans += b[t - sum];
        }
    }


    cout << ans << '\n';
}
