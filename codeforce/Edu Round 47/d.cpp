#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) { return (b % a) ? gcd(b % a, a) : a; }

vector<pair<int, int> > ans;

int main(){
    long long n, m;
    scanf("%lld%lld", &n, &m);

    if(m > n * (n - 1) / 2 || m < n - 1) printf("Impossible\n");
    else {
        for(int i = 2; i <= n; i++) ans.push_back({1, i});
        for(int i = 3; i <= n && ans.size() < m; i++) {
            for(int j = 2; j < i; j++) {
                if(gcd(i, j) == 1) ans.push_back({j, i});
            }
        }

        if(ans.size() < m) printf("Impossible\n");
        else {
            printf("Possible\n");
            for(int i = 0; i < m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }

    return 0;
}
