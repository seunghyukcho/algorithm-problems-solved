#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(;t > 0; t--){
        int v, e;
        cin >> v >> e;

        vector<vector<int> > graph(v + 1);
        vector<int> color(v + 1, 0);

        for(int i = 0; i < e; i++){
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        for(int k = 1; k <= v; k++){
            if(color[k])continue;

            queue<pair<int, int> > q;
            q.push({k, 1});
            color[k] = 1;

            while(!q.empty()){
                int vertex = q.front().first;
                int clr = q.front().second;
                q.pop();

                for(auto i : graph[vertex]){
                    if(!color[i]){
                        color[i] = -clr;
                        q.push({i, -clr});
                    }
                }
            }
        }
        bool check = true;
        for(int i = 1; i <= v && check; i++){
            for(auto j : graph[i]){
                if(color[i] == color[j]){
                    check = false;
                    break;
                }
            }
        }

        if(check)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
