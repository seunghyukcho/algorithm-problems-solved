#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v, e, ans;
int num;
vector<vector<int> > graph1(10002);
vector<vector<int> > graph2(10002);
vector<int> check(10002, 0);
vector<vector<int> > allscc;

void dfs1(int v){
    check[v] = -1;
    for(auto i : graph1[v]){
        if(!check[i]){
            dfs1(i);
        }
    }
    check[v] = num;
    num -= 1;
}

void dfs2(int v, vector<int> &scc){
    scc.push_back(v);
    check[v] = 0;
    for(auto i : graph2[v]){
        if(check[i]){
            dfs2(i, scc);
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    num = v;
    for(int i = 1; i <= v; i++){
        if(!check[i])dfs1(i);
    }

    vector<pair<int, int> > dfstree;
    for(int i = 1; i <= v; i++)
        dfstree.push_back({check[i], i});

    sort(dfstree.begin(), dfstree.end());
    for(auto i : dfstree){
        if(check[i.second]){
            vector<int> scc;
            dfs2(i.second, scc);
            ans++;
            sort(scc.begin(), scc.end());
            allscc.push_back(scc);
        }
    }

    cout << ans << '\n';
   
    sort(allscc.begin(), allscc.end()); 
    for(auto v : allscc){
        for(auto i : v)cout << i << ' ';
        cout << -1 << '\n';
    }

    return 0;
}
