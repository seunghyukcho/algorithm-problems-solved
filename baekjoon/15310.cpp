#include<iostream>
#include<algorithm>

using namespace std;

struct R {
    int w, h;
};

bool comp(R r1, R r2) { if(r1.w == r2.w) return r1.h < r2.h; return r1.w < r2.w; }

long long D[3002][3002][2];
int n, k;
R rec[3002];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> rec[i].w >> rec[i].h;
    sort(rec, rec + n, comp);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) D[j][i][0] = D[j][i][1] = 1e9;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++) {
            long long d1 = D[i - 1][j][0] * D[i - 1][j][1];
            long long d2 = (D[i - 1][j - 1][0] + rec[i].w) * (D[i - 1][j - 1][1] + rec[i].h);

            if(d1 < d2) {
                D[i][j][0] = D[i - 1][j][0];
                D[i][j][1] = D[i - 1][j][1];
            }
            else {
                D[i][j][0] = D[i - 1][j - 1][0] + rec[i].w;
                D[i][j][1] = D[i - 1][j - 1][1] + rec[i].h;
            }
        }


    cout << D[n][k][0] * D[n][k][1] << '\n';

    return 0;
}
