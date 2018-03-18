#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    int painting = 0;
    int ans = 0;

    cin >> n >> m;

    vector<vector<int> > map(n, vector<int>(m, 0));
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j]){
                queue<pair<int, int> > q;
                int size = 0;

                q.push({i, j});
                painting++;
                map[i][j] = 0;
                 
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    size++;

                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int newx = x + dir[k][0];
                        int newy = y + dir[k][1];
                        
                        if(newx < 0 || newy < 0 || newx >= n || newy >= m || !map[newx][newy])
                            continue;        
                        
                        q.push({newx, newy});
                        map[newx][newy] = 0;
                    }
                }

                ans = ans > size ? ans : size;
            }
        }
    }

    cout << painting << '\n' << ans << '\n';

    return 0;
}
