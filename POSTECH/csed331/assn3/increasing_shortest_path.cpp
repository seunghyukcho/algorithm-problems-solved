#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct F{
    long long cost;
    int n, prev_e;
};

bool operator<(F p1, F p2){
    return p1.cost > p2.cost;
}
int t, v, e;

int main(){
    for(cin >> t; t > 0; t--){
        priority_queue<F> q;

        cin >> v >> e;
        vector<vector<pair<int, int> > > graph(v);
        vector<long long> total_cost(v, -1);

        for(int i = 0; i < e; i++){
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }

        q.push({0, 0, 0});
        total_cost[0] = 0;

        while(!q.empty()){
            auto here = q.top();
            q.pop();
            if(total_cost[here.n] > here.cost)
                continue;
            for(auto next : graph[here.n]){
                if(next.second <= here.prev_e)
                    continue;

                if(total_cost[next.first] == -1){
                    total_cost[next.first] = here.cost + next.second;
                    if(next.first != v - 1)
                        q.push({total_cost[next.first], next.first, next.second});
                }
                else{
                    if(total_cost[next.first] > here.cost + next.second){
                        total_cost[next.first] = here.cost + next.second;
                        if(next.first != v - 1)
                            q.push({total_cost[next.first], next.first, next.second});
                    }
                }
            }
        }

        cout << total_cost[v - 1] << '\n';
    }
    return 0;
}
