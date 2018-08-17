#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point {
    int x, y;
} P[8002];

bool comp(Point p1, Point p2) {
    return atan2(p1.y, p1.x) < atan2(p2.y, p2.x);
}

int n, k, qx, qy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> P[i].x >> P[i].y;
    cin >> qx >> qy;
    for(int i = 1; i <= n; i++) {
        P[i].x -= qx;
        P[i].y -= qy;
    }

    sort(P + 1, P + 1 + n, comp);
    int piece = n / k;
    if(n % k != 0) cout << "NO\n";
    else {
        for(int start = 1; start <= n; start++) {
            bool check = true;

            for(int i = 1; i <= k && check; i++) {
                int next1 = (start + piece * i + 1) % n, next2 = (start + piece * i) % n;
                //cout << atan2(P[next1].y, P[next1].x) << ' ' << atan2(P[next2].y, P[next2].x) << '\n';

                if(atan2(P[next1].y, P[next1].x) == atan2(P[next2].y, P[next2].x)) check = false;
            }

            if(check) {
                cout << "YES\n";
                return 0;
            }
        }

        cout << "NO\n";
    }

    return 0;
}
