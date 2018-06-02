#include<iostream>
#include<vector>

using namespace std;

int c, n, m;
long long ans;
bool visited[15];

void dfs(int num, int total, vector<vector<int> > &f){
    if(total == n){
        ans++;
        return;
    }

    for(int i = num + 1; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            for(auto next : f[i]){
                if(!visited[next] && i < next){
                    visited[next] = true;
                    dfs(i, total + 2, f);
                    visited[next] = false;
                }
            }
            visited[i] = false;
        }
    }
}

int main(){
    for(cin >> c; c > 0; c--){
        cin >> n >> m;
        vector<vector<int> > f(n + 1);

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            f[a].push_back(b);
            f[b].push_back(a);
        }

        ans = 0;
        for(int i = 0; i < n; i++)
            visited[i] = false;

        dfs(-1, 0, f);

        cout << ans << '\n';
    }

    return 0;
}
