#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n;
vector<vector<int> > graph(2010);
int weight[2010][2010];
int capacity[2010][2010];
int previous[2010];
long long d[2010];
int source, sink;

void spfa(){
    queue<int> q;
    q.push(0);

    for(int i = 1; i <= 2 * n + 1; i++) {
        previous[i] = -1;
        d[i] = 1e9;
    }

    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(auto next : graph[here]) {
            if(capacity[here][next] && d[here] + weight[here][next] < d[next]){
                if(next != 2 * n + 1 || d[next] == 1e9) q.push(next);
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
        if(previous[2 * n + 1] == -1) break;

        int ret = 0;
        for(int here = 2 * n + 1; here != 0; here = previous[here]) {
            ret += 1 * weight[previous[here]][here];
            capacity[previous[here]][here] -= 1;
            capacity[here][previous[here]] += 1;
        }

        ans += ret;
    }

    return ans;
}

int main(){
    cin >> n;
    source = 0;
    sink = 2 * n + 1;

    for(int i = 1; i <= n; i++){
        graph[0].push_back(i);
        graph[i].push_back(0);
        capacity[0][i] = 1;

        graph[n + i].push_back(sink);
        graph[sink].push_back(n + i);
        capacity[n + i][sink] = 1;

        for(int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            graph[i].push_back(n + j);
            graph[n + j].push_back(i);
            weight[i][n + j] = num;
            capacity[i][n + j] = 1;
        }
    }

    cout << mcmf() << '\n';

    return 0;
}
