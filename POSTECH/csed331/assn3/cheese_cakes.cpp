#include<iostream>
#include<queue>

using namespace std;

struct P{
    int x, y;
};

int t, h, w;
int grid[1002][1002];
int dir[8][2] = {0, 1,
                1, 1,
                1, 0,
                1, -1,
                0, -1,
                -1, -1,
                -1, 0,
                -1, 1};

int main(){
    for(cin >> t; t > 0; t--){
        int ans = 0;

        cin >> h >> w;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> grid[i][j];

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++){
                if(grid[i][j]){
                    queue<P> q;

                    ans++;
                    grid[i][j] = 0;
                    q.push({i, j});

                    while(!q.empty()){
                        P here = q.front();
                        q.pop();

                        for(int k = 0; k < 8; k++){
                            P next = {here.x + dir[k][0], here.y + dir[k][1]};

                            if(next.x < 0 || next.y < 0 || next.x >= h || next.y >= w)
                                continue;
                            if(grid[next.x][next.y]){
                                grid[next.x][next.y] = 0;
                                q.push(next);
                            }
                        }
                    }
                }
            }

            cout << ans << '\n';
    }
    return 0;
}
