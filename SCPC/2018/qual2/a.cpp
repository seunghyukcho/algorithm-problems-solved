#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int pmin[200010], ans;
int num[200010], N, t;

int main(){
    int cs = 1;
    for(scanf("%d", &t); cs <= t; cs++) {
        ans = 0;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d", &num[i]);
        pmin[N + 1] = 1e9;
        for(int i = N; i > 0; i--) pmin[i] = min(num[i], pmin[i + 1]);

        int pmax = 0;
        for(int i = 1; i <= N; i++) {
            if(num[i] > pmax && num[i] < pmin[i + 1]) ans++;
            pmax = max(pmax, num[i]);
        }

        printf("Case #%d\n%d\n", cs, ans);
    }

    return 0;
}
