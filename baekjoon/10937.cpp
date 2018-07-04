#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int table[4][4] = {
    {100, 70, 40, 0},
    {70, 50, 30, 0},
    {40, 30, 20, 0}
};

int n;
vector<vector<int> > graph(200);
int weight[200][200];
int capacity[200][200];
int board[12][12];
int previous[200], d[200];

void spfa(){
    queue<int> q;
    q.push(0);

    for(int i = 1; i <= n * n + 1; i++) {
        previous[i] = -1;
        d[i] = 1e9;
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : graph[here]) {
            if(capacity[here][next] && d[here] + weight[here][next] < d[next]){
                if(next != n * n + 1 || d[next] == 1e9) q.push(next);
                d[next] = d[here] + weight[here][next];
                previous[next] = here;
            }
        }
    }
}

int mcmf(){
    int ans = 0;

    while(true){
        spfa();
        if(previous[n * n + 1] == -1) break;

        int ret = 0;
        for(int here = n * n + 1; here != 0; here = previous[here]) {
            ret += 1 * weight[previous[here]][here];
            capacity[previous[here]][here] -= 1;
            capacity[here][previous[here]] += 1;
        }

        if(ret < 0) ans += ret;
        else break;
    }

    return ans;
}

int main(){
    char ch;
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> ch;

            if(ch == 'A') board[i][j] = 0;
            else if(ch == 'B') board[i][j] = 1;
            else if(ch == 'C') board[i][j] = 2;
            else board[i][j] = 3;
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int here = (i - 1) * n + j;

            if(((i % 2) + (j % 2)) % 2){
                for(int k = 0; k < 4; k++){
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if(nextx <= 0 || nexty <= 0 || nextx > n || nexty > n) continue;

                    int next = (nextx - 1) * n + nexty;
                    graph[here].push_back(next);
                    graph[next].push_back(here);
                    capacity[here][next] = 1;
                    weight[next][here] = table[board[i][j]][board[nextx][nexty]];
                    weight[here][next] = -weight[next][here];
                }
            }

            graph[here].push_back(0);
            graph[here].push_back(n * n + 1);
            graph[0].push_back(here);
            graph[n * n + 1].push_back(here);

            capacity[0][here] = 1;
            capacity[here][n * n + 1] = 1;
        }

    cout << -mcmf() << '\n';
}
