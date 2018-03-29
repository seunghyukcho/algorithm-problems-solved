#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct F{
    long long cost;
    int idx, node;
};
bool operator<(F f1, F f2){
    return f1.cost > f2.cost;
}
int t, v, e;

int main(){
    for(cin >> t; t > 0; t--){
        long long ans = -1;
        cin >> v >> e;

        vector<pair<int, long long> > edge(e);
        vector<vector<pair<int, int> > > graph(v);
        for(int i = 0; i < e; i++){
            int u, v, w;
            cin >> u >> v >> w;

            edge[i] = {w, -1};
            graph[u].push_back({v, i});
            graph[v].push_back({u, i});
        }

        priority_queue<F> pq;
        for(auto here : graph[0]){
            pq.push({edge[here.second].first, here.second, here.first});
            edge[here.second].second = edge[here.second].first;
        }

        while(!pq.empty()){
            auto here = pq.top();
            pq.pop();
            if(edge[here.idx].second < here.cost)
                continue;
            for(auto next : graph[here.node]){
                if(edge[next.second].first <= edge[here.idx].first)
                    continue;
                if(edge[next.second].second == -1){
                    edge[next.second].second = here.cost + edge[next.second].first;
                    if(next.first == v - 1){
                        if(ans == -1)
                            ans = edge[next.second].second;
                        else
                            ans = min(ans, edge[next.second].second);
                    }
                    else
                        pq.push({edge[next.second].second, next.second, next.first});
                }
                else if(edge[next.second].second > here.cost + edge[next.second].first){
                    if(next.first == v - 1){
                        if(ans == -1)
                            ans = edge[next.second].second;
                        else
                            ans = min(ans, edge[next.second].second);
                    }
                    else
                        pq.push({edge[next.second].second, next.second, next.first});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
