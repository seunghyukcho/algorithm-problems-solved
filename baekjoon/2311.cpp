#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

long long MAX = 5e10;

using namespace std;

struct MCMF {
    struct Edge {
        int s;
        int e;
        int capacity;
        int cost;
    };

    struct Edge_idx {
        int e;
        int idx;
    };

    vector<Edge_idx> V[1010];
    vector<Edge> E;

    void setEdge(int start, int end, int capacity, int cost){
        int n = E.size();
        E.push_back({start, end, capacity, cost});
        E.push_back({end, start, 0, -cost});

        V[start].push_back({end, n});
        V[end].push_back({start, n + 1});
    }

    int source, sink, vSize = 1010;
    long long dist[1010];
    long long check[1010], prev[1010];

    vector<int> spfa() {
        for(int i = 0; i <= vSize; i++) {
            check[i] = 0;
            dist[i] = MAX;
        }

        queue<int> q;
        q.push(source);

        dist[source] = 0;

        while(!q.empty()) {
            int here = q.front();
            q.pop();

            check[here] = 0;
            for(auto edge : V[here]){
                int next = edge.e;
                int idx = edge.idx;

                if(E[idx].capacity && dist[here] + E[idx].cost < dist[next]) {
                    dist[next] = dist[here] + E[idx].cost;
                    prev[next] = idx;

                    if(next != sink && check[next] == 0) {
                        check[next] = 1;
                        q.push(next);
                    }
                }
            }
        }

        vector<int> ret;
        if(dist[sink] == MAX) return ret;
        else {
            for(int here = sink; here != source; here = E[prev[here]].s) {
                ret.push_back(prev[here]);
            }
            return ret;
        }
    }

    pair<long, long> mcmf() {
        long long flow = 0, cost = 0;

        while(true){
            vector<int> path = spfa();
            if(path.size() == 0) break;

            long long f = MAX, c = 0;
            for(auto here : path) {
                f = f < E[here].capacity ? f : E[here].capacity;
                c += (long long)E[here].cost;
            }

            cost += f * c;
            flow += f;

            for(auto here : path) {
                E[here].capacity -= f;
                E[here ^ 1].capacity += f;
            }
        }

        return {flow, cost};
    }

} G;

int main(){
    int n, m;
    cin >> n >> m;

    G.source = 0;
    G.sink = n + 1;

    for(int i = 0; i < m; i++){
        int s, e, c;
        cin >> s >> e >> c;

        G.setEdge(s, e, 1, c);
        G.setEdge(e, s, 1, -c);
    }

    G.setEdge(0, 1, 2, 0);
    G.setEdge(n, n + 1, 2, 0);

    cout << G.mcmf().second << '\n';

}
