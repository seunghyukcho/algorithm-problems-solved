#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, k, doll[502];
long long psum[502], ppsum[502];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &doll[i]);

    for(int i = 1; i <= n; i++) {
        psum[i] = (long long)doll[i] + psum[i - 1];
        ppsum[i] = (long long)doll[i] * doll[i] + ppsum[i - 1];
    }

    long double ans = 1e9;
    for(; k <= n; k++) {
        for(int i = 1; i + k - 1 <= n; i++) {
            int s = i, e = i + k - 1;
            long double avg = (psum[e] - psum[s - 1]) / (long double)k;
            long double pp = ppsum[e] - ppsum[s - 1];

            long double sigma = pp / (long double)k - avg * avg;

            ans = min(ans, sqrt(sigma));
        }
    }

    printf("%.9Lf\n", ans);

    return 0;
}
