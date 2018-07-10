#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct P {
    int x, y, h;
};

bool comp(P p1, P p2) { return p1.y < p2.y; }

long long psum[10010];
int t, n, D[10010];
P memo[10010];

int check(int i, int j) {
    return (memo[j].y - psum[j] + psum[i] >= (long long)memo[i].y) ? 0 : 1;
}

int check2(int i, int j) {
    return (memo[i].y + psum[j - 1] - psum[i] <= (long long)memo[j].y) ? 0 : 1;
}

int main(){
    setbuf(stdout, NULL);

    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        printf("Case #%d\n", cs);
        int ans = 1e9;

        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d%d%d", &memo[i].x, &memo[i].y, &memo[i].h);

        sort(memo + 1, memo + n + 1, comp);
        for(int i = 1; i <= n; i++) psum[i] = psum[i - 1] + memo[i].h;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(i == 1) D[j] = check(i, j);
                else {
                    if(i > j) D[j] = D[j] + check2(j, i);
                    else if(i <= j) {
                        D[j] = D[j] + check(i, j);
                        for(int k = 1; k <= i - 1; k++) {
                            long long right_most = (long long)memo[k].y + psum[i - 1] - psum[k];
                            long long left_most = (long long)memo[j].y - psum[j] + psum[i - 1];

                            if(right_most > left_most) continue;
                            D[j] = min(D[j], D[k] + check(i, j));
                        }
                    }
                }
                //cout << i << ' ' << j << ' ' << D[i][j] << '\n';

                if(i == n) ans = min(ans, D[j]);
            }

    	printf("%d\n", ans);
    }
}
