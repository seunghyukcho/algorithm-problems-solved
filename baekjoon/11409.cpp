#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX 1000000000

using namespace std;

int n, m;

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

                if(E[idx].capacity > 0 && dist[here] + E[idx].cost < dist[next]) {
                    dist[next] = dist[here] + E[idx].cost;
                    prev[next] = idx;

                    if(check[next] == 0) {
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
    pair<long long, long long> mcmf() {
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
    scanf("%d%d", &n, &m);

    G.source = 0;
    G.sink = n + m + 1;

    for(int i = 1; i <= n; i++) {
        int num, job, cost;
        for(scanf("%d", &num); num > 0; num--) {
            scanf("%d%d", &job, &cost);

            G.setEdge(i, n + job, 1, -cost);
        }

        G.setEdge(0, i, 1, 0);
    }

    for(int i = 1; i <= m; i++) G.setEdge(n + i, n + m + 1, 1, 0);

    auto result = G.mcmf();

    printf("%lld\n%lld\n", result.first, -result.second);

    return 0;
}
