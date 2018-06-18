#include<iostream>

using namespace std;

int t, h, w, dir[4][3][2] = {{0, 0, 1, 0, 1, 1}, {0, 0, 0, 1, 1, 1}, {0, 0, 0, 1, 1, 0}, {0, 0, 1, -1, 1, 0}};
char board[22][22];
long long ans;

void cover(int x, int y){
    if(x == h){
        ans++;
        return;
    }

    if(board[x][y] == '#')
        cover(x + (y + 1) / w, (y + 1) % w);
    else{
        for(int k = 0; k < 4; k++){
            int i;
            for(i = 0; i < 3; i++){
                int nextx = x + dir[k][i][0];
                int nexty = y + dir[k][i][1];

                if(nextx < 0 || nexty < 0 || nextx >= h || nexty >= w || board[nextx][nexty] == '#')
                    break;
            }

            if(i == 3){
                for(i = 0; i < 3; i++){
                    int nextx = x + dir[k][i][0];
                    int nexty = y + dir[k][i][1];

                    board[nextx][nexty] = '#';
                }
                cover(x + (y + 1) / w, (y + 1) % w);
                for(i = 0; i < 3; i++){
                    int nextx = x + dir[k][i][0];
                    int nexty = y + dir[k][i][1];

                    board[nextx][nexty] = '.';
                }
            }
        }
    }
}

int main(){
    for(cin >> t; t > 0; t--){
        cin >> h >> w;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> board[i][j];

        ans = 0;
        cover(0, 0);

        cout << ans << '\n';
    }

    return 0;
}
