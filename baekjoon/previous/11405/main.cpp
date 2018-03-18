#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int> > c(202, vector<int>(202, 0));
vector<vector<int> > d(202, vector<int>(202, 0));

void input();
int flow();
int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    input();
    cout << flow() << '\n';

    return 0;
}

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> c[m + i][n + m + 1];
    for(int i = 1; i <= m; i++)cin >> c[0][i];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> d[i][m + j];
            d[m + j][i] = -d[i][m + j];
            c[i][m + j] = 1e9;
        }
    }
}

int flow(){
    int ans = 0;
    vector<vector<int> > flow(202, vector<int>(202, 0));
    while(1){
        queue<int> q;
        vector<bool> check(202);
        vector<int> dis(202, 1e9);
        vector<int> parent(202, -1);
        dis[0] = 0;
        q.push(0);
        check[0] = true;
        while(!q.empty()){
            int here = q.front(); q.pop();
            check[here] = false;
            for(int i = 0; i <= n + m + 1; i++){
                if(c[here][i] - flow[here][i] > 0 && dis[i] > dis[here] + d[here][i]){
                    dis[i] = dis[here] + d[here][i];
                    parent[i] = here;
                    if(!check[i]){
                        q.push(i);
                        check[i] = true;
                    }
                }
            }
        }

        if(parent[n + m + 1] == -1)break;
        
        int minflow = 1e9;
        for(int i = n + m + 1; i != 0; i = parent[i])minflow = min(minflow, c[parent[i]][i] - flow[parent[i]][i]);
        for(int i = n + m + 1; i != 0; i = parent[i]){
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
            ans += minflow * d[parent[i]][i];
        }
    }

    return ans;
}
