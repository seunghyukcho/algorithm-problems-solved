#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

bool num[1000002];
int t, n;

int isexist(int n){
    int ret = 1e9;

    for(int i = 1; i <= (int)sqrt(n); i++){
        if(n % i == 0){
            if(num[i])
                ret = min(ret, i);
            else if(num[n / i])
                ret = min(ret, n / i);
        }
    }

    return (ret == 1e9 ? n : ret);
}

int main(){
    for(scanf("%d", &t); t > 0; t--){
        scanf("%d", &n);

        long long ans = 0;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            num[a[i]] = true;
        }
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            ans += isexist(a[i]);
        }
        printf("%lld\n", ans);

        for(int i = 0; i < n; i++)
            num[a[i]] = false;
    }

    return 0;
}
