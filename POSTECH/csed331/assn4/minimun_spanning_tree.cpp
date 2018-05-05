#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
    int start, end;
    int cost;
};
bool comp(Edge e1, Edge e2){
    return e1.cost < e2.cost;
}

int t;
int v, e;
vector<int> parent(10002);
vector<int> r(10002);

int root(int v){
    if(v == parent[v]) return parent[v];
    else return parent[v] = root(parent[v]);
}
void link(int v1, int v2){
    if(r[v1] <= r[v2]){
        parent[parent[v1]] = parent[v2];
        r[v2] += r[v1] + 1;
    }
    else{
        parent[parent[v2]] = parent[v1];
        r[v1] += r[v2] + 1;
    }
}

int main(){
    for(cin >> t; t > 0; t--){
        long long ans = 0;
        int cnt = 0;
        vector<Edge> edges;

        cin >> v >> e;

        for(int i = 0; i < e; i++){
            int start, end, c;

            cin >> start >> end >> c;
            edges.push_back({start, end, c});
        }
        for(int i = 0; i < v; i++){
            parent[i] = i;
            r[i] = 0;
        }

        sort(edges.begin(), edges.end(), comp);

        for(auto here : edges){
            if(root(here.start) != root(here.end)){
                ans += here.cost;
                link(here.start, here.end);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
