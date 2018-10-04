#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct A {
    ll w, h;
} area[50002];

bool comp(A a, A b) {
    return a.w == b.w ? a.h < b.h : a.w < b.w;
}

const int MAXN = 50002;
struct ConvexHull {
    int sz, p, n;
    ll la[MAXN], lb[MAXN];

    double cross(int x, int y){ return (double)(lb[y] - lb[x]) / (la[x] - la[y]); }

    void insert(ll p, ll q){
        la[sz] = p;
        lb[sz] = q;

        while(sz > 1 && cross(sz - 1, sz - 2) > cross(sz - 1, sz)){
            la[sz - 1] = la[sz];
            lb[sz - 1] = lb[sz];
            sz--;
        }
        sz++;
    }

    ll query1(ll x){
        while (p + 1 < sz && cross(p, p + 1) <= x) p++;
        return lb[p] + la[p] * x;
    }

    ll query2(ll x){
        int l = 0, r = sz - 1;
        while (l != r) {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x) l = m + 1;
            else r = m;
        }
        return la[l] * x + lb[l];
    }
} cht;

vector<A> areas;
int n;
ll D[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> area[i].w >> area[i].h;
    }
    sort(area, area + n, comp);

    for(int i = 0; i < n; i++) {
        while(!areas.empty() && areas.back().h <= area[i].h) {
            areas.pop_back();
        }

        areas.push_back(area[i]);
    }

    reverse(areas.begin(), areas.end());
    cht.insert(areas[0].w, 0);
    for(int i = 0; i < areas.size(); i++) {
        D[i + 1] = cht.query2(areas[i].h);
        cht.insert(areas[i + 1].w, D[i + 1]);
    }

    cout << D[areas.size()] << '\n';
}
