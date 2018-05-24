#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long v, e, mod = 2017231920182101;
vector<long long> D;
int t;

long long dfs(long long here, vector<vector<long long> >& graph){
    if(D[here] != -1)
        return D[here];

    long long ret = 0;
    for(auto next : graph[here]){
        ret = ((ret % mod) + (dfs(next, graph) % mod)) % mod;
    }

    return D[here] = ret;
}

int main(){
    for(cin >> t; t > 0; t--){
        cin >> v >> e;
        D = vector<long long>(v, -1);
        vector<vector<long long> > graph(v);

        for(int i = 0; i < e; i++){
            long long start, end;
            cin >> start >> end;
            
            graph[start].push_back(end);
        }

        D[v - 1] = 1;
        cout << dfs(0, graph) << '\n';
    }

    return 0;
}
