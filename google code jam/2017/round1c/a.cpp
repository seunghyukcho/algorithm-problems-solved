#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct Cake{
    int r, h;
};

bool operator<(Cake c1, Cake c2){
    return (double)c1.r * c1.h > (double)c2.r * c2.h;
}

int t, n, k;
Cake cake[1002];

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        double ans, store = 0;
        int mx_r = 0;

        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int h, r;
            cin >> r >> h;

            cake[i] = {r, h};
        }
        sort(cake, cake + n);

        for(int i = 0; i < k - 1; i++){
            store += 2.0 * M_PI * cake[i].r * cake[i].h;
            mx_r = max(mx_r, cake[i].r);
        }

        ans = store;
        for(int i = k - 1; i < n; i++){
            int mx_r2 = max(mx_r, cake[i].r);
            ans = max(ans, store + 2.0 * M_PI * cake[i].r * cake[i].h + M_PI * (double)mx_r2 * mx_r2);
        }

        printf("Case #%d: %.6f\n", cs, ans);
    }

    return 0;
}
