#include<iostream>

using namespace std;

int c, h, w;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
long long ans;
char board[25][25];

void dfs(){
    bool check = true;

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            if(board[i][j] == '.'){
                check = false;
                for(int k = 0; k < 4; k++){
                    int nextx[2] = {i + dir[k][0], i + dir[(k + 1) % 4][0]};
                    int nexty[2] = {j + dir[k][1], j + dir[(k + 1) % 4][1]};

                    if(nextx[0] < 0 || nexty[0] < 0 || nextx[1] < 0 || nexty[1] < 0)
                        continue;
                    if(nextx[0] >= h || nexty[0] >= w || nextx[1] >= h || nexty[1] >= w)
                        continue;
                    if(board[nextx[0]][nexty[0]] != '.' || board[nextx[1]][nexty[1]] != '.')
                        continue;

                    board[nextx[0]][nexty[0]] = board[nextx[1]][nexty[1]] = board[i][j] = '#';
                    dfs();
                    board[nextx[0]][nexty[0]] = board[nextx[1]][nexty[1]] = board[i][j] = '.';
                }
            }
        }

    if(check)
        ans++;
}

int main(){
    for(cin >> c; c > 0; c--){
        cin >> h >> w;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> board[i][j];

        ans = 0;
        dfs();

        cout << ans << '\n';
    }

    return 0;
}
