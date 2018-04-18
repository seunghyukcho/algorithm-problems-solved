#include<iostream>
#include<vector>

using namespace std;

long long max(long long a, long long b){ return a < b ? b : a; }

struct C{
    int m, s, p;
};
bool operator<(C c1, C c2){ return (c1.m * c1.s + c1.p < c2.m * c2.s + c2.p); }
int t, r, b, c;
C casher[1002];
long long D[12][12][25];

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        long long ans = -1;
        int put = 0;
        cin >> r >> b >> c;
        casher[0].m = 0;
        for(int i = 1; i <= c; i++)
            cin >> casher[i].m >> casher[i].s >> casher[i].p;
        for(int i = 0; i <= c; i++)
            for(int j = 0; j <= i; j++)
                for(int k = 0; k <= b; k++)
                    D[i][j][k] = -1;
        D[0][0][0] = 0;
        for(int i = 0; i < c; i++){
            for(int j = 0; j <= i; j++){
                for(int k = 0; k <= b; k++){
                    if(D[i][j][k] == -1)
                        continue;
                    D[i + 1][j][k] = D[i][j][k];
                    for(int l = 1; l <= casher[i + 1].m && k + casher[i + 1].m <= b; l++){
                        if(D[i + 1][j + 1][k + l] == -1 || D[i + 1][j + 1][k + l] > max(D[i][j][k], casher[i + 1].s * l + casher[i + 1].p))
                            D[i + 1][j + 1][k + l] = max(D[i][j][k], casher[i + 1].s * l + casher[i + 1].p);
                    }
                }
            }
        }

        for(int i = 1; i <= r; i++)
            if(ans == -1 || (D[c][i][b] != -1 && D[c][i][b] != 0 && ans > D[c][i][b]))
                ans = D[c][i][b];

        printf("Case #%d: %lld\n", cs, ans);
    }
}
