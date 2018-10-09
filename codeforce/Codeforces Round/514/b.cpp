#include<bits/stdc++.h>

using namespace std;

int n, m, dirx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, diry[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
char board[1002][1002];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> board[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '#') {
                bool flag = true;
                for(int k = 0; k < 8 && flag; k++) {
                    int nextx = i + dirx[k];
                    int nexty = j + diry[k];

                    if(nextx <= 0 || nexty <= 0 || nextx >= n - 1 || nexty >= m - 1) continue;
                    bool flag2 = true;
                    for(int d = 0; d < 8 && flag2; d++) {
                        int nnextx = nextx + dirx[d];
                        int nnexty = nexty + diry[d];
                        if(board[nnextx][nnexty] == '.') flag2 = false;
                    }

                    flag = !flag2;
                }

                if(flag) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}
