#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int t, v, e;
struct Edge{
    int w, pos;
};
struct Vertex{
    long long cost;
    int pos;
};

bool operator<(Vertex v1, Vertex v2){return v1.cost > v2.cost;}

int main(){
    for(cin >> t; t > 0; t--){
        cin >> v >> e;
        vector<vector<Edge> > graph(2 * v + 1);

        for(int i = 0; i < e; i++){
            int start, next, p;
            cin >> start >> next >> p;

            graph[start].push_back({p, next});
            graph[start].push_back({0, next + v});
            graph[start + v].push_back({p, next + v});
        }

        priority_queue<Vertex> pq;
        vector<long long> cost(2 * v + 1, -1);

        cost[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto here = pq.top();
            pq.pop();

            if(here.cost > cost[here.pos])
                continue;

            for(auto e : graph[here.pos]){
                if(cost[e.pos] == -1 || cost[e.pos] > here.cost + e.w){
                    cost[e.pos] = here.cost + e.w;
                    if(e.pos != v - 1 && e.pos != 2 * v - 1)
                        pq.push({cost[e.pos], e.pos});
                }
            }
        }

        printf("%lld\n", min(cost[v - 1], cost[2 * v - 1]));
    }

    return 0;
}
