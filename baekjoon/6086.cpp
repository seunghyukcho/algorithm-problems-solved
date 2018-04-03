#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int vertex(char ch){
    if(ch >= 'a')
        return 'Z' + ch - 'a';
    else
        return ch - 'A';
}

int n;
vector<vector<int> > graph(vertex('z') + 1);
int Capacity[102][102];
int Flow[102][102];

int get_flow(int u, int MaxCapacity){
    if(u == vertex('Z'))
        return MaxCapacity;
    for(int next : graph[u]){
        int c = Capacity[u][next] - Flow[u][next];
        if(int f = get_flow(next, min(MaxCapacity, c)) > 0){
            Flow[u][next] += f;
            return f;
        }
        c = Flow[next][u];
        if(int f = get_flow(next, min(MaxCapacity, c)) > 0){
            Flow[next][u] -= f;
            return f;
        }
    }

    return 0;
}

int get_max_flow(){
    int total = 0;
    while(int f = get_flow(vertex('A'), 1e9) > 0){
        total += f;
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
        Capacity[vertex(u)][vertex(v)] = c;
        Capacity[vertex(u)][vertex(v)] = c;
        graph[vertex(u)].push_back(vertex(v));
        graph[vertex(v)].push_back(vertex(u));
    }

    cout << get_max_flow() << '\n';

    return 0;
}
