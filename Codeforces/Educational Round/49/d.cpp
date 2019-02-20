#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long ans = 0;
int a[200002], c[200002], n, cnt = 1;
int visited[200002];

int dfs1(int here) {
    int next = a[here];

    if(visited[next] != 0) return visited[next] == cnt++ ? next : -1;

    visited[here] = cnt;
    return dfs1(next);
}

int dfs2(int here, int start, int mincost) {
    mincost = min(mincost, c[here]);

    int next = a[here];
    if(next == start) return mincost;

    return dfs2(next, start, mincost);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            int result = dfs1(i);

            if(result != -1) ans += dfs2(a[result], result, c[result]);
        }
    }

    cout << ans << '\n';
    return 0;
}
