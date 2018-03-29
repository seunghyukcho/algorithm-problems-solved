#include<iostream>
#include<algorithm>

using namespace std;

struct H{
    int e, s;
};

int t, n, q;
long long D[102][102];
double G[102][102];
H horse[102];

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> n >> q;

        for(int i = 1; i <= n; i++)
            cin >> horse[i].e >> horse[i].s;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                cin >> D[i][j];
                if(i == j)
                    D[i][j] = 0;
            }

        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++){
                    if(D[i][k] != -1 && D[k][j] != -1){
                        if(D[i][j] != -1)
                            D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                        else
                            D[i][j] = D[i][k] + D[k][j];
                    }

                    if(D[i][j] != -1 && D[i][j] <= horse[i].e)
                        G[i][j] = (double)D[i][j] / horse[i].s;
                    else
                        G[i][j] = -1;
                }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++){
                    if(G[i][k] != -1 && G[k][j] != -1){
                        if(G[i][j] != -1)
                            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                        else
                            G[i][j] = G[i][k] + G[k][j];
                    }
                }

        printf("Case #%d: ", cs);
        for(int i = 0; i < q; i++){
            int u, k;
            cin >> u >> k;
            printf("%.6f ", G[u][k]);
        }
        printf("\n");
    }

    return 0;
}
