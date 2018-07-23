#include<iostream>
#include<algorithm>

using namespace std;

int n, shu[100002], ans;
int visited[100002];

void dfs(int v) {
    int next = shu[v];
    if(!visited[next]) {
        visited[next] = visited[v] + 1;
        dfs(next);
    } else if(visited[next] != -1) {
        ans += visited[v] - visited[next] + 1;
    }

    visited[v] = -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> shu[i];

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}
