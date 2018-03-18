#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > g(n + 1);
    vector<int> check(n + 1, 1e9);
    bool cycle = false;
     
    for(int i = 0; i < m; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        g[start].push_back({end, cost});
    }

    check[1] = 0;

    for(int j = 0; j < n; j++){
        for(int i = 1; i <= n; i++){
            for(auto p : g[i]){
                int next = p.first;
                int cost = p.second;

                if(check[i] != 1e9 && check[next] > check[i] + cost){
                    check[next] = check[i] + cost;
                    if(j == n - 1)cycle = true;
                }
            }
        }
    }

    if(cycle)cout << -1 << '\n';
    else
        for(int i = 2; i <= n; i++)cout << (check[i] != 1e9 ? check[i] : -1) << '\n';

    return 0;
}
