#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, subtree[500002];
int color[100002], parent[100002][2];
vector<pair<int, int> > tree[100002];
bool visited[100002];

int dfs(int here, int prev) {
    int sum = 0;

    for(auto next : tree[here]) {
        if(next.first == prev || visited[next.first]) continue;

        sum += dfs(next.first, here);
    }

    subtree[here] = sum + 1;
    return sum + 1;
}

int centroid(int here, int prev, int sz) {
    for(auto next : tree[here]) {
        if(next.first == prev || visited[next.first]) continue;
        if(subtree[next.first] > sz / 2) return centroid(next.first, here, sz);
    }

    return here;
}

void centroid_tree(int here) {
    visited[here] = true;

    for(auto edge : tree[here]) {
        int next = edge.first;
        int cost = edge.second;

        if(visited[next]) continue;

        int size = dfs(next, here);

        int center = centroid(next, here, size);
        parent[center][0] = here;
        parent[center][1] = cost;

        centroid_tree(center);
    }

    visited[here] = false;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    dfs(1, 0);
    int center = centroid(1, 0, n);
    parent[center][0] = center;
    centroid_tree(center);

    for(int i = 1; i <= n; i++) cout << parent[i][0] << ' ';

    /*for(scanf("%d", &m); m > 0; m--){
        int num, v;
        scanf("%d", &num);
        if(num == 1) {
            scanf("%d", &v);
            color[v] ^= 1;
        } else {
            //for(int i = 1; i <= n; i++) visited[i] = false;
            int result = longest(center);
            printf("%d\n", (result == -1e9 - 1 ? -1 : result));
        }
    }*/

    return 0;
}
