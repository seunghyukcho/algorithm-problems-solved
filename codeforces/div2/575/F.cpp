#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pr;

priority_queue<ll> ans;
int n, m, k;
vector<pr> graph[200002];

void dijkstra(int start)
{
    int times = k + 1;
    priority_queue<pair<ll, int> > pq;
    vector<ll> dist(n + 1, -1);

    pq.push({ 0, start });
    dist[start] = 0;

    while(!pq.empty() && times)
    {
        ll d = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(d > dist[here]) continue;
        times--;

        if(here > start) 
        {
            ans.push(d);
            if(ans.size() > k) ans.pop();
        }

        for(pr edge : graph[here])
        {
            int next = edge.first;
            ll newDist = d + edge.second;

            if(dist[next] == -1 || dist[next] > newDist)
            {
                dist[next] = newDist;
                pq.push({ -newDist, next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }

    for(int i = 1; i <= n; i++) dijkstra(i);

    cout << ans.top() << '\n';
}