#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>

using namespace std;

int n, m;
map<string, int> idx;
vector<int> graph[510];
vector<int>
bool bfs(string start, string end) {
    if(!idx.count(start) || !idx.count(end)) return false;
    int s = idx[start];
    int e = idx[end];

    queue<int> q;
    vector<bool> visited(510, false);
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        for(auto next : graph[here]) {
            if(next == e) return true;
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int main(){
    cin >> n >> m;

    int index = 1;
    for(int i = 0; i < n; i++) {
        string s1, s2, rel;
        cin >> s1 >> rel >> s2;

        if(!idx.count(s1)) idx[s1] = index++;
        if(!idx.count(s2)) idx[s2] = index++;

        if(rel == "is-a") graph[idx[s1]].push_back(idx[s2]);
        else graph[idx[s2]].push_back(idx[s1]);
    }

    for(int i = 1; i <= 6; i++) {
        for(auto here : graph[i]) cout << here << ' ';
        cout << '\n';
    }

    for(int j = 0; j < m; j++) {
        string s1, s2, rel;
        cin >> s1 >> rel >> s2;

        if(rel == "is-a") cout << (bfs(s1, s2) ? "true\n" : "false\n");
        else cout << (bfs(s2, s1) ? "true\n" : "false\n");
    }

    return 0;
}
