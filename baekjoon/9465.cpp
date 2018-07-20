#include<iostream>

using namespace std;

int D[100002][2];
int t, n, score[100002][2];

int main(){
    for(scanf("%d", &t); t > 0; t--) {
        scanf("%d", &n);
        for(int j = 0; j < 2; j++) for(int i = 1; i <= n; i++) scanf("%d", &score[i][j]);
        D[1][0] = score[1][0]; D[1][1] = score[1][1];

        int ans = max(D[1][0], D[1][1]);
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                D[i][j] = max(D[i - 1][(j + 1) % 2], max(D[i - 2][0], D[i - 2][1])) + score[i][j];
                ans = max(ans, D[i][j]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
