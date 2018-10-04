#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int next, cost;

    Edge(int n1, int n2): next(n1), cost(n2) {}
};

bool operator<(Edge e1, Edge e2) {
    return e1.cost > e2.cost;
}

int v, e, weight[2502];
ll dist[2502][2502], D[2502];
vector<Edge> graph[2502];
vector<ll> visited(2502, INT64_MAX);

void dijkstra(int start) {
    for(int i = 1; i <= v; i++) visited[i] = INT64_MAX;
    visited[start] = 0;

    priority_queue<Edge> pq;
    pq.push(Edge(start, 0));

    while(!pq.empty()) {
        int here = pq.top().next;
        int d = pq.top().cost;
        pq.pop();

        if(d > visited[here]) continue;

        for(auto edge : graph[here]) {
            int next = edge.next, cost = edge.cost;

            if(visited[next] > visited[here] + cost) {
                visited[next] = visited[here] + cost;
                pq.push(Edge(next, visited[next]));
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        dist[start][i] = weight[start] * visited[i];
    }
}

ll dy(int here, int prev) {
    if(D[here]) return D[here];

    ll ret = dist[here][v];

    for(auto edge : graph[here]) {
        if(edge.next == prev || edge.next == 1) continue;
        if(dist[here][edge.next] >= ret) continue;

        ll result = dist[here][edge.next] + dy(edge.next, here);
        ret = ret > result ? result : ret;
    }

    return D[here] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for(int i = 1; i <= v; i++) cin >> weight[i];
    for(int i = 1; i <= e; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        graph[u].push_back(Edge(v, c));
        graph[v].push_back(Edge(u, c));
    }

    for(int i = 1; i < v; i++) {
        dijkstra(i);
    }
    cout << dist[1][v] << '\n';
    // cout << dy(1, 0) << '\n';
}
