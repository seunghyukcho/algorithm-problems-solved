#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

int n, m, k;
vector<edge> graph[20002];

void dijkstra(int start)
{
    vector<int> dist(20002, -1);
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while(!pq.empty())
    {
        int here = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;
        for(auto e : graph[here])
        {
            int next = e.first, d = e.second;

            if(dist[next] == -1 || dist[next] > cost + d)
            {
                dist[next] = d + cost;
                pq.push({ -dist[next], next });
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == -1) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({ e, c });
    }

    dijkstra(k);
}