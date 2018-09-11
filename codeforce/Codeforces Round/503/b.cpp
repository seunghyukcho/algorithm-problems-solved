#include<iostream>

using namespace std;

bool visited[1002];
int n, p[1002];

void dfs(int here) {
    if(visited[here]) {
        cout << here << ' ';
        return;
    }

    visited[here] = true;
    dfs(p[here]);
    visited[here] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) {
        dfs(i);
    }
    cout << '\n';

    return 0;
}
