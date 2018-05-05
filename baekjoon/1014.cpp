#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, m;
vector<bool> visit(105, false);
char map[12][12];
int cnt[12][12];
int capacity[105][105];
int flow[105][105];

int get_flow(int u, int MaxCapacity, int count){
    if(u == count)
        return MaxCapacity;

    for(int i = 0; i <= count; i++){
        if(visit[i])
            continue;

        if(int c = capacity[u][i] - flow[u][i] > 0){
            visit[i] = true;
            int f = get_flow(i, min(c, MaxCapacity), count);

            if(f > 0){
                flow[u][i] += f;
                return f;
            }
        }

        if(int c = flow[i][u] > 0){
            visit[i] = true;

            int f = get_flow(i, min(c, MaxCapacity), count);

            if(f > 0){
                flow[i][u] -= f;
                return f;
            }
        }
    }

    return 0;
}

int get_max_flow(int count){
    int f, ret = 0;
    visit[0] = true;

    do{
        for(int i = 1; i <= count; i++)
            visit[i] = false;
        f = get_flow(0, 1e9, count);
        ret += f;
    } while(f > 0);

    return ret;
}

int main(){
    int dir[6][2] = {-1, -1, -1, 1, 0, -1, 0, 1, 1, -1, 1, 1};
    int count;

    for(cin >> t; t > 0; t--){
        int check = 0;
        count = 1;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> map[i][j];

                if(map[i][j] != 'x'){
                    cnt[i][j] = count++;
                    if(j % 2 == 0)
                        check++;
                }
                else
                    cnt[i][j] = -1;
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(cnt[i][j] == -1)
                    continue;
                if(j % 2 == 0)
                    capacity[cnt[i][j]][count] = 1;
                else{
                    capacity[0][cnt[i][j]] = 1;

                    for(int k = 0; k < 6; k++){
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];

                        if(nextx >= 0 && nexty >= 0 && nextx < n && nexty < m && cnt[nextx][nexty] != -1)
                            capacity[cnt[i][j]][cnt[nextx][nexty]] = 1;
                    }
                }
            }

        cout << count - 1 - get_max_flow(count) << '\n';
    }

    return 0;
}
