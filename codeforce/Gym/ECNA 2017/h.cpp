#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int m, n;
int color[102][102];
int visited[102][102];
int dir[8][2] = {0, 1,
                0, -1,
                1, 0,
                -1, 0,
                1, 1,
                1, -1,
                -1, 1,
                -1, -1};
vector<int> bacteria(1, 0);

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++)
            if(s[j - 1] == '#') color[i][j] = 1;
    }

    int index = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            if(!visited[i][j] && color[i][j] == 1) {
                queue<pair<int, int> > q;
                int sz = 1;
                visited[i][j] = index;

                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 8; k++) {
                        int nextx = x + dir[k][0];
                        int nexty = y + dir[k][1];

                        if(nextx < 1 || nexty < 1 || nextx > m || nexty > n || visited[nextx][nexty] || !color[nextx][nexty]) continue;
                        visited[nextx][nexty] = index;
                        sz++;
                        q.push({nextx, nexty});
                    }
                }
                index++;
                bacteria.push_back(sz);
            }
        }

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            if(visited[i][j]) {
                int idx = visited[i][j];
                int count = 0;
                for(int k = 0; k < 8 && count < 2; k++) {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];

                    if(nextx < 1 || nexty < 1 || nextx > m || nexty > n || idx != visited[nextx][nexty]) continue;
                    count++;
                }

                if(count == 2) bacteria[idx]--;
            }
        }

    int ans = 0;
    for(int i = 1; i < bacteria.size(); i++)
        if(bacteria[i] == 0) ans++;

    cout << ans << '\n';

    return 0;
}
