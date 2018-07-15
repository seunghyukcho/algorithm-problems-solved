#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int parent[100002], cost[100002];
int n, m, c, h, k;
int ans;

bool comp(int a, int b) { return a > b; }

int find(int n) {
    if(parent[n] == n) return parent[n];
    else return parent[n] = find(parent[n]);
}

bool check(int u, int v) {
    return find(u) == find(v);
}

void merge(int u, int v) {
    if(!check(u, v)) {
        cost[find(v)] += cost[find(u)];
        parent[find(u)] = parent[find(v)];
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        cost[i] = 1;
    }

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    cin >> c >> h >> k;
    vector<int> component;
    ans = cost[find(c)];

    for(int i = 1; i <= n; i++) {
        if(parent[i] == i && !check(i, h) && !check(i, c)) component.push_back(cost[i]);
    }
    sort(component.begin(), component.end(), comp);

    for(int i = 0; i < k && i < component.size(); i++) ans += component[i];

    cout << ans << '\n';

    return 0;
}
