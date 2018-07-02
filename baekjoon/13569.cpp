#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

vector<vector<int> > graph(500);
long long flow[500][500], capacity[500][500], level[500], demand[500][2];
double num[300][300];
bool visited[500];
int n, m;

long long min(long long a, long long b){ return a < b ? a : b; }

void bfs(int start){
    for(int i = 0; i < n + m + 4; i++) level[i] = -1;
    level[start] = 0;

    queue<pair<int, int> > q;
    q.push({start, 0});

    while(!q.empty()){
        auto here = q.front(); q.pop();

        for(auto next : graph[here.first]){
            if(level[next] == -1 && (capacity[here.first][next] - flow[here.first][next] > 0
            || flow[next][here.first] > 0)){
                level[next] = here.second + 1;
                q.push({next, here.second + 1});
            }
        }
    }
}

long long dfs(int here, long long minflow){
    if(here == n + m + 3) return minflow;
    for(auto next : graph[here]){
        if(!visited[next] && level[next] - level[here] == 1){
            if(int f = capacity[here][next] - flow[here][next] > 0){
                visited[next] = true;
                int result = dfs(next, min(minflow, f));
                if(result){
                    flow[here][next] += result;
                    return result;
                }
            }

            if(int f = flow[next][here] > 0){
                visited[next] = true;
                int result = dfs(next, min(minflow, f));
                if(result){
                    flow[next][here] -= result;
                    return result;
                }
            }
        }
    }

    return 0;
}

long long max_flow(){
    long long ret = 0;

    while(true){
        for(int i = 0; i < n + m + 4; i++) visited[i] = false;
        bfs(n + m + 2);

        if(level[n + m + 3] == -1) break;
        ret += dfs(n + m + 2, 1e9);
    }

    return ret;
}

int main(){
    long long total_demand = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        double input;
        for(int j = 1; j <= m; j++){
            cin >> input;
            num[i][j] = input;

            int f = floor(input);
            int c = ceil(input);

            graph[i].push_back(i + j);
            graph[i + j].push_back(i);

            capacity[i][i + j] = c - f;
            demand[i][1] += f;
            demand[i + j][0] += f;
        }

        cin >> input;
        num[i][m + 1] = input;
        int f = floor(input);
        int c = ceil(input);

        graph[0].push_back(i);
        graph[i].push_back(0);

        capacity[0][i] = c - f;
        demand[0][1] += f;
        demand[i][0] += f;
    }

    for(int i = 1; i <= m; i++){
        double input;
        cin >> input;

        num[n + 1][i] = input;
        int f = floor(input);
        int c = ceil(input);

        graph[n + i].push_back(n + m + 1);
        graph[n + m + 1].push_back(n + i);

        capacity[n + i][n + m + 1] = c - f;
        demand[n + i][1] = f;
        demand[n + m + 1][0] = f;
    }

    for(int i = 0; i <= n + m + 1; i++){
        graph[n + m + 2].push_back(i);
        graph[i].push_back(n + m + 2);

        capacity[n + m + 2][i] = demand[i][0];
        total_demand += demand[i][0];

        graph[n + m + 3].push_back(i);
        graph[i].push_back(n + m + 3);

        capacity[i][n + m + 3] = demand[i][1];
    }

    graph[n + m + 1].push_back(0);
    graph[0].push_back(n + m + 1);
    capacity[n + m + 1][0] = 1e9;

    max_flow();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << flow[i][i + j] + (long long)floor(num[i][j])<< ' ';
        cout << flow[0][i] + (long long)floor(num[n + 1][i]) << '\n';
    }

    for(int i = 1; i <= m; i++)
        cout << flow[n + 1][n + i + 1] + (long long)floor(num[n + 1][i]) << ' ';

    cout << '\n';

    return 0;
}
