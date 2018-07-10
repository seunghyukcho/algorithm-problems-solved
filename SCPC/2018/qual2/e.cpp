#include<cstdio>
#include<iostream>

using namespace std;

int t, n, h;
long long psum[1000002];
long long ppsum[1000002];
double D[1000002][2];

pair<double, double> C(int i, int j) {
    double k = (psum[j] - psum[i - 1]) / (j - i + 1.0);

    double ret1 = ppsum[j] - ppsum[i - 1];
    double ret2 = 2 * k * (psum[j] - psum[i - 1]);
    double ret3 = (j - i + 1) * k * k;

    return { ret1 - ret2 + ret3, k };
}

int main(){
    setbuf(stdout, NULL);
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        printf("Case #%d\n", cs);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            cin >> psum[i];
            ppsum[i] = psum[i] * psum[i] + ppsum[i - 1];
            psum[i] += psum[i - 1];
        }

        for(int i = 1; i <= n; i++) {
            auto result = C(1, i);
            D[i][0] = result.first; D[i][1] = result.second;

            for(int j = 2; j <= i; j++) {
                result = C(j, i);
                if(result.second >= D[j - 1][1]) {
                    if(D[i][0] > D[j - 1][0] + result.first) {
                        D[i][0] = D[j - 1][0] + result.first;
                        D[i][1] = result.second;
                    }
                }
            }
        }

        printf("%.9f\n", D[n][0]);
    }

    return 0;
}
