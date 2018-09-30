#include<iostream>
#include<algorithm>

using namespace std;

int n, D[10002], ans;

struct Point {
    int a, w;
} P[10002];

bool comp(Point p1, Point p2) {
    return p1.a < p2.a;
}

int labeling(int x) {
    if(D[x] != 1e9) return D[x];

    int now = P[x].a, ret = 0;

    for(int j = x + 1; j < n; j++) {
        if(now + P[j].w > P[j].a) {
            if(now > P[j].a) ret++;
        }
        else if(now + P[j].w == P[j].a) {
            ret += labeling(j);
            break;
        }
        else {
            D[x] = min(D[x], ret + labeling(j));
            ret++;
        }

        now += P[j].w;
    }

    return D[x] = min(D[x], ret);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> P[i].a;
    for(int i = 0; i < n; i++) {
        cin >> P[i].w;
        D[i] = 1e9;
    }

    sort(P, P + n, comp);

    ans = 1e9;
    for(int i = 0; i < n; i++) {
        ans = min(ans, i + labeling(i));
    }

    cout << ans << '\n';

    return 0;
}
