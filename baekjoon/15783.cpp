#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool visited[100002];
vector<int> graph1[100002], graph2[100002];
vector<vector<int> > component;
vector<int> kosaraju;

int n, m;
int ans;

void dfs(int here) {
    visited[here] = true;
    for(auto next : graph1[here]) {
        if(!visited[next]) dfs(next);
    }

    kosaraju.push_back(here);
}

int main(){
    int index[100002];
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph1[s].push_back(e);
        graph2[e].push_back(s);
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i);
    }

    reverse(kosaraju.begin(), kosaraju.end());
    for(int i = 0; i < n; i++) visited[i] = false;

    int idx = 0;
    for(auto start : kosaraju) {
        if(visited[start]) continue;

        queue<int> q; vector<int> group;
        q.push(start); group.push_back(start);
        visited[start] = true; index[start] = idx;

        while(!q.empty()) {
            int here = q.front(); q.pop();
            for(auto next : graph2[here]) {
                if(visited[next]) continue;
                index[next] = idx;
                group.push_back(next); q.push(next);
                visited[next] = true;
            }
        }

        component.push_back(group);
        idx++;
    }

    for(int i = 0; i < idx; i++) {
        bool check = true;
        for(int here : component[i]) {
            for(int next : graph2[here]) {
                if(index[next] != i) {
                    check = false;
                    break;
                }
            }
            if(!check) break;
        }

        if(check) ans++;
    }

    cout << ans << '\n';
    return 0;
}
