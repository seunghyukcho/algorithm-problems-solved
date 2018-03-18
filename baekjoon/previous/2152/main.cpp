#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int> > graph1(10002);
vector<vector<int> > graph2(10002);
vector<pair<int, int> > check;
vector<int> number(10002, 0);
vector<int> scc(10002, 0);
vector<int> visited(10002, 0);
int num;

void dfs1(int v){
    check[v].first = -1;
    for(auto i : graph1[v]){
        if(!check[i].first)
            dfs1(i);
    }
    check[v].first = num--;
}

void dfs2(int v, int tag){
    number[v] = tag;
    scc[tag]++;
    for(auto i : graph2[v]){
        if(!number[i])
            dfs2(i, tag);
    }
}

void dfs3(int v, int e){
    for(auto i : graph1[v]){
        if(i == e){
            if(scc[number[i]])visited[e] = visited[v] + scc[number[i]];
            else if(!visited[i]){
                visited[i] = visited[v];
                if(scc[number[i]]){
                    visited[v] += scc[number[i]];
                    scc[number[i]] = 0;
                    dfs3(i, e);
                else dfs3(i, e);
                visited[i] = 0;
            }
        }
    }
}
int main(){
    int n, m, s, t;
    int cnt = 1;
    cin >> n >> m >> s >> t;
    num = n;

    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

    for(int i = 0; i <= n; i++)check.push_back({0, i});
    for(int i = 1; i <= n; i++){
        if(!check[i].first){
            dfs1(i);
        }
    }
    sort(check.begin() + 1, check.end());
    for(int i = 1; i <= n; i++){
        if(!number[i]){
            dfs2(i, cnt);
            cnt++;
        }
    }
    cout << bfs(s, t) << '\n';

    return 0;
}
