#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int t, v, e;

int main(){
    for(cin >> t; t > 0; t--){
        int ans = -1;
        cin >> v >> e;

        vector<vector<int> > graph(v);
        for(int i = 0; i < e; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        queue<pair<int, int> > q;
        vector<bool> vis(v, false);

        q.push({0, 0});
        vis[0] = true;

        while(!q.empty() && ans == -1){
            int here = q.front().first;
            int dis = q.front().second;
            q.pop();

            for(auto next : graph[here]){
                if(!vis[next]){
                    if(next == v - 1){
                        ans = dis + 1;
                        break;
                    }
                    else{
                        vis[next] = true;
                        q.push({next, dis + 1});
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
