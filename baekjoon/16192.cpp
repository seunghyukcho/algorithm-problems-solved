#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

int n, q, qx, qy, idx[2002];
point region[2002];

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d%d", &region[i].first, &region[i].second);
    for(int i = 0; i < q; i++) {
        int mindist = 1e9, cnt = 0;
        scanf("%d%d", &qx, &qy);

        for(int j = 0; j < n; j++) {
            int dist = pow(qx - region[j].first, 2) + pow(qy - region[j].second, 2);
            if(dist < mindist) {
                cnt = 1;
                idx[cnt] = j;
                mindist = dist;
            }
            else if(dist == mindist) {
                idx[++cnt] = j;
            }
        }

        if(cnt == 0) printf("NONE\n");
        else if(cnt == 1) printf("REGION %d\n", idx[cnt] + 1);
        else if(cnt == 2) printf("LINE %d %d\n", idx[1] + 1, idx[2] + 1);
        else printf("POINT\n");
    }
}
