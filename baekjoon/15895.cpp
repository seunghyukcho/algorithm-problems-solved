#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct Query
{
    int v, c;
} Q[200002];

bool comp(Query& q1, Query& q2)
{
    return q1.c < q2.c;
}

int D[2000000], n, m, c, conv[200002];
vector<int> childs[200002], color[200002];
pair<int, int> segment[200002];

void dfs(int here, int prev, int& idx)
{
    segment[here].first = idx;
    for(int next : childs[here])
    {
        if(next == prev) continue;
        dfs(next, here, idx);
    }

    segment[here].second = idx;
    conv[here] = idx++;
}

int query1(int s, int e, int start = 1, int end = n, int v = 1)
{
    if(e < start || end < s) return 0;
    if(s <= start && end <= e) return D[v];

    int mid = (start + end) / 2;
    return query1(s, e, start, mid, 2 * v) + query1(s, e, mid + 1, end, 2 * v + 1);
}

void query2(int idx, int start = 1, int end = n, int v = 1)
{
    D[v]++;
    if(start == end) return;

    int mid = (start + end) / 2;
    if(idx <= mid) query2(idx, start, mid, 2 * v);
    else query2(idx, mid + 1, end, 2 * v + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll ans = 0;
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++)
    {
        int clr;
        cin >> clr;
        color[clr].push_back(i);
    }

    for(int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        childs[v1].push_back(v2), childs[v2].push_back(v1);
    }

    for(int i = 0; i < m; i++) cin >> Q[i].v >> Q[i].c;
    sort(Q, Q + m, comp);

    int idx = 1, colorHere = 1;
    dfs(1, 1, idx);

    for(int i = 0; i < m; i++)
    {
        for(; colorHere <= Q[i].c; colorHere++)
            for(int v : color[colorHere]) query2(conv[v]);
        ans = (ans + query1(segment[Q[i].v].first, segment[Q[i].v].second)) % MOD;
    }

    cout << ans << '\n';
}