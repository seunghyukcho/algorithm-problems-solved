#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, m;
int height[1002][1002];
int D[1002][1002];
int lexoD[1002][1002];

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int dfs(int x, int y){
    if(D[x][y] == -1){
        int ret = 0;

        for(int k = 0; k < 4; k++){
            int nextx = x + dir[k][0];
            int nexty = y + dir[k][1];

            if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m || height[nextx][nexty] <= height[x][y])
                continue;

            int d = dfs(nextx, nexty);


            if(d > ret){
                ret = d;
                lexoD[x][y] = k;
            }
            else if(d == ret){
                int nextheight = height[x + dir[lexoD[x][y]][0]][y + dir[lexoD[x][y]][1]];

                if(height[nextx][nexty] < nextheight)
                    lexoD[x][y] = k;
            }

        }

        D[x][y] = ret + 1;
    }

    return D[x][y];
}

void dfs_answer(int x, int y){
    cout << height[x][y] << ' ';

    if(lexoD[x][y] == -1)
        return;

    int nextx = x + dir[lexoD[x][y]][0];
    int nexty = y + dir[lexoD[x][y]][1];

    dfs_answer(nextx, nexty);
}

int main(){
    for(cin >> t; t > 0; t--){
        int ans = 0;
        int startx, starty;

        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> height[i][j];
                D[i][j] = -1;
                lexoD[i][j] = -1;
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                int d = dfs(i, j);
                if(d > ans){
                    ans = d;
                    startx = i;
                    starty = j;
                }
                else if(d == ans && height[i][j] < height[startx][starty]){
                    startx = i;
                    starty = j;
                }
            }

        cout << ans << '\n';
        dfs_answer(startx, starty);
        cout << '\n';
    }

    return 0;
}
