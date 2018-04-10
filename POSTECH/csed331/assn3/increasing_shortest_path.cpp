#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int t, v, e;
struct Edge{
    int w, end, idx;
    bool visit;
    long long cost;
};

bool operator<(Edge v1, Edge v2){return v1.cost > v2.cost;}
bool comp(Edge e1, Edge e2){return e1.w > e2.w;}
int search(vector<Edge> g, int val){
    int l = 0, r = g.size() - 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(g[mid].w <= val)
            r = mid - 1;
        else
            l = mid;
    }

    if(g[l].w <= val)
        return -1;
    else
        return l;
}
int main(){
    for(cin >> t; t > 0; t--){
        cin >> v >> e;

        long long ans = -1;
        vector<vector<Edge> > graph(v + 1);
        vector<Edge> cost(2 * e + 5);

        for(int i = 0; i < e; i++){
            int s, t, w;
            cin >> s >> t >> w;

            Edge new_edge1 = {w, t, 2 * i, false, -1};
            Edge new_edge2 = {w, s, 2 * i + 1, false, -1};
            cost[2 * i] = new_edge1;
            cost[2 * i + 1] = new_edge2;

            graph[s].push_back(new_edge1);
            graph[t].push_back(new_edge2);
        }

        for(int i = 0; i < v; i++)
            sort(graph[i].begin(), graph[i].end(), comp);

        priority_queue<Edge> pq;
        for(int i = 0; i < graph[0].size(); i++){
            auto change = graph[0][i];
            change.cost = change.w;
            change.visit = true;
            cost[change.idx] = change;
            pq.push(change);
        }

        while(!pq.empty()){
            auto here = pq.top();
            pq.pop();

            if(here.cost > cost[here.idx].cost)
                continue;

            for(int i = search(graph[here.end], here.w); i >= 0 && !cost[graph[here.end][i].idx].visit; i--){
                auto next = graph[here.end][i];
                cost[next.idx].cost = here.cost + next.w;
                cost[next.idx].visit = true;

                if(next.end == v - 1){
                    if(ans == -1 || ans > cost[next.idx].cost)
                        ans = cost[next.idx].cost;
                }
                else
                    pq.push(cost[next.idx]);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
