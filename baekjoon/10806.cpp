#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// variables for find bridges
vector<int> ori[100001];
int px[200002], py[200002], brid[200002];
 
int chk[100001], up[100001];
 
int gety(int x, int e)
{
    return x == px[e] ? py[e] : px[e];
}
 
void dfs(int x, int l, int d)
{
    chk[x] = 1; up[x] = d;
    for (int i=0;i<ori[x].size();i++){
        int e = ori[x][i];
        if (e == l) continue;
 
        int y = gety(x,e);
        if (chk[y] == 0){
            dfs(y,e,d+1);
            if (up[y] > d) brid[e] = 1;
        }
        if (up[x] > up[y]) up[x] = up[y];
    }
}
 
// variables for make supernodes
vector<int> sup[100001];
int par[100001], grp[100001], pri[100001];
 
int find(int x)
{
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}
 
// variables for make new edges
vector<int> leaf;
 
void pre(int x, int p)
{
    if (sup[x].size() == 1) 
        leaf.push_back(x);
    for (int i=0;i<sup[x].size();i++){
        int y = sup[x][i];
        if (p == y) continue;
        pre(y,x);
    }
}
 
int main()
{
    // input
    int N,M;
    scanf ("%d %d",&N,&M);
    for (int i=1;i<=M;i++){
        scanf ("%d %d",&px[i],&py[i]);
        ori[px[i]].push_back(i);
        ori[py[i]].push_back(i);
    }
 
    // find bridges
    dfs(1,0,0);
 
    // make supernodes
    for (int i=1;i<=N;i++) 
        par[i] = i;
    for (int i=1;i<=M;i++) 
        if (!brid[i]){
            int x = find(px[i]);
            int y = find(py[i]);
            if (x != y) par[x] = y;
        }

    int G = 0;
    for (int i=1;i<=N;i++)
        if (par[i] == i){
            grp[i] = ++G;
            pri[G] = i;
        }

    for (int i=1;i<=N;i++) 
        grp[i] = grp[find(i)];

    for (int i=1;i<=M;i++){
        int x = grp[find(px[i])];
        int y = grp[find(py[i])];
        if (x != y){
            sup[x].push_back(y);
            sup[y].push_back(x);
        }
    }
    for (int i=1;i<=G;i++){
        sort(sup[i].begin(),sup[i].end());
        sup[i].erase(unique(sup[i].begin(),sup[i].end()),sup[i].end());
    }
 
    // make new edges
    vector<pair<int, int> > ans;
    pre(1,-1);
 
    if (G == 2) 
        ans.push_back(make_pair(1,2));
    else if (leaf.size() > 1){
        int sz = (leaf.size() + 1) / 2;
        int half = leaf.size() / 2;
        for (int i=0;i<sz;i++) 
            ans.push_back(make_pair(leaf[i],leaf[i+half]));
    }
 
    printf ("%lu\n",ans.size());
    for (int i=0;i<ans.size();i++) 
        printf ("%d %d\n",pri[ans[i].first],pri[ans[i].second]);
 
    return 0;
}