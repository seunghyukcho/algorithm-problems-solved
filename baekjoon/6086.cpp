#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int vertex(char ch){
    if(ch >= 'a')
        return 'Z' - 'A' + ch - 'a' + 1;
    else
        return ch - 'A';
}

int n;
vector<vector<int> > graph(vertex('z') + 1);
vector<bool> visit(60, false);
int Capacity[60][60];
int Flow[60][60];

int get_flow(int u, int MaxCapacity){
    if(u == vertex('Z'))
        return MaxCapacity;
    for(int next : graph[u]){
        if(visit[next])
            continue;

        visit[next] = true;
        int c = Flow[next][u] ? Flow[next][u] + Capacity[next][u] : Capacity[u][next] - Flow[u][next];
        int f = get_flow(next, min(MaxCapacity, c));

        if(f > 0){
            Flow[u][next] += max(0, f - Flow[next][u]);
            Flow[next][u] = max(0, Flow[next][u] - f);
            return f;
        }
    }

    return 0;
}

int get_max_flow(){
    int total = 0, f;
    f = get_flow(vertex('A'), 1e9);

    while(f > 0){
        total += f;
        for(int i = 1; i < 60; i++)
            visit[i] = false;
        f = get_flow(vertex('A'), 1e9);
    }
    return total;
}
int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        char u, v;
        int c;
        cin >> u >> v >> c;
        Capacity[vertex(u)][vertex(v)] += c;
        Capacity[vertex(v)][vertex(u)] += c;
        graph[vertex(u)].push_back(vertex(v));
        graph[vertex(v)].push_back(vertex(u));
    }

    visit[vertex('A')] = true;
    cout << get_max_flow() << '\n';

    return 0;
}
