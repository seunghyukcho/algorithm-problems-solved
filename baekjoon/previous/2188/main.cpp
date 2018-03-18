#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<bool> > adj(202, vector<bool>(202, false));
vector<int> amatch, bmatch;
vector<bool> visited;

bool dfs(int a){
    if(visited[a])return false;
    visited[a] = true;
    for(int b = 0; b < m; b++){
        if(adj[a][b]){
            if(bmatch[b] == -1 || dfs(bmatch[b])){
                amatch[a] = b;
                bmatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartitematch(){
    int size = 0;
    amatch = vector<int>(n, -1);
    bmatch = vector<int>(m, -1);
    for(int i = 0; i < n; i++){
        visited = vector<bool>(n, false);
        if(dfs(i))size++;
    }

    return size;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        for(;num > 0; num--){
            int n;
            cin >> n;
            adj[i][n - 1] = true;
        }
    }

    cout << bipartitematch() << '\n';

    return 0;
}
