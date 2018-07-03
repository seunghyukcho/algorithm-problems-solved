#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k;
vector<vector<int> > graph(2010);
vector<int> level(2010);
int flow[2010][2010];
int capacity[2010][2010];
bool visited[2010];

int dfs(int here, int minflow){
    if(here == n + m + 1)
        return minflow;

    for(auto next : graph[here]){
        if(!visited[next] && level[next] - level[here] == 1){
            if(int f = capacity[here][next] - flow[here][next] > 0){
                visited[next] = true;
                int result = dfs(next, min(minflow, f));
                if(result != 0){
                    flow[here][next] += result;
                    return result;
                }
            }

            if(int f = flow[next][here] > 0){
                visited[next] = true;
                int result = dfs(next, min(minflow, f));
                if(result != 0){
                    flow[next][here] -= result;
                    return result;
                }
            }
        }
    }

    return 0;
}

void bfs(){
    queue<pair<int, int> > q;
    q.push({0, 0});

    while(!q.empty()){
        auto here = q.front(); q.pop();

        for(int next : graph[here.first]){
            if(level[next] == -1 && (capacity[here.first][next] - flow[here.first][next] > 0 || flow[next][here.first] > 0)){
                level[next] = here.second + 1;
                q.push({next, here.second + 1});
            }
        }
    }
}

int max_flow(){
    int ret = 0;

    while(1){
        level[0] = 0;
        for(int i = 1; i <= n + m + 2; i++) level[i] = -1;
        bfs();

        if(level[n + m + 1] == -1) break;

        for(int i = 1; i <= n + m + 2; i++) visited[i] = false;

        int result = dfs(0, 1e9);

        if(result == 0) break;

        ret += result;
    }

    return ret;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int num;
        for(cin >> num; num > 0; num--){
            int next;
            cin >> next;

            graph[i].push_back(next + n);
            graph[next + n].push_back(i);
            capacity[i][next + n] = 1;
        }
        graph[n + m + 2].push_back(i);
        graph[i].push_back(n + m + 2);
        graph[0].push_back(i);
        graph[i].push_back(0);

        capacity[0][i] = 1;
        capacity[n + m + 2][i] = 1e9;
    }

    for(int i = 1; i <= m; i++) {
        graph[i + n].push_back(n + m + 1);
        capacity[i + n][n + m + 1] = 1;
    }

    graph[0].push_back(n + m + 2);
    capacity[0][n + m + 2] = k;

    cout << max_flow() << '\n';

    return 0;
}
