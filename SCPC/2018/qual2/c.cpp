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

bool operator<(Edge v1, Edge v2){ return v1.cost > v2.cost; }
bool comp(Edge e1, Edge e2){ return e1.w > e2.w; }

struct Graph {
    int source, sink;
    vector<int> left;
    vector<long long> dist;
    vector<vector<Edge> > graph;
    vector<Edge> cost;

    void set_edge(int s, int e, int w) {
        int idx = cost.size();

        Edge new_edge1 = {w, e, idx, false, -1};
        Edge new_edge2 = {w, s, idx + 1, false, -1};
        cost.push_back(new_edge1);
        cost.push_back(new_edge2);

        graph[s].push_back(new_edge1);
        graph[e].push_back(new_edge2);
    }

    void dijkstra() {
        for(int i = 1; i <= v; i++) {
            sort(graph[i].begin(), graph[i].end(), comp);
            dist[i] = -1;
        }

        priority_queue<Edge> pq;
        for(int i = 0; i < graph[source].size(); i++) {
            auto edge = graph[source][i];
            edge.cost = edge.w;
            edge.visit = true;
            cost[edge.idx] = edge;
            pq.push(edge);

            dist[edge.end] = edge.w;
        }
        dist[source] = 0;

        while(!pq.empty()) {
            auto here = pq.top();
            pq.pop();

            if(here.cost > cost[here.idx].cost)
                continue;

            int i;
            for(i = left[here.end]; i < graph[here.end].size() && graph[here.end][i].w >= here.w; i++){
                auto next = graph[here.end][i];
                cost[next.idx].cost = here.cost + next.w;
                cost[next.idx].visit = true;

                if(next.end != sink) pq.push(cost[next.idx]);

                if(dist[next.end] == -1 || dist[next.end] > cost[next.idx].cost)
                    dist[next.end] = cost[next.idx].cost;
            }

            left[here.end] = i;
        }
    }
};

int main(){
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        long long ans = -1;
        Graph G1, G2;
        scanf("%d%d", &v, &e);
        G1.dist = G2.dist = vector<long long>(v + 1);
        G1.graph = G2.graph = vector<vector<Edge> >(v + 1);
        G1.left = G2.left = vector<int>(v + 1, 0);

        for(int i = 0; i < e; i++) {
            int start, end, weight;
            scanf("%d%d%d", &start, &end, &weight);
            G1.set_edge(start, end, weight);
            G2.set_edge(start, end, weight);
        }

        G1.source = G2.sink = 1;
        G1.sink = G2.source = v;

        G1.dijkstra();
        G2.dijkstra();

        for(int i = 1; i <= v; i++) {
            if((G1.dist[i] != -1 && G2.dist[i] != -1) && (ans == -1 || ans > G1.dist[i] + G2.dist[i])) ans = G1.dist[i] + G2.dist[i];
        }

        printf("Case #%d\n%lld\n", cs, ans);
    }

    return 0;
}
