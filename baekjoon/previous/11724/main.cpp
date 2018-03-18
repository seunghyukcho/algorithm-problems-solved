#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> check(n + 1, false);
    queue<int> q;
    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            ans++;
            q.push(i);
            check[i] = true;

            while(!q.empty()){
                int here = q.front();
                q.pop();

                for(int next : g[here]){
                    if(!check[next]){
                        check[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
    
