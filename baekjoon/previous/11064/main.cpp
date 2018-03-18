#include<iostream>
#include<vector>

using namespace std;

vector<int> dep[40002];
vector<pair<int, int> > con[40002];
vector<int> parv(40002);
vector<int> par(40002);
vector<int> tree(40002);
int n, D, maxh;

void dfs(int n, int p, int d){
    par[n] = p;
    dep[d].push_back(n);
    maxh = max(maxh, d);

    for(auto i : con[n]){
        if(i.first == p)
            continue;
        parv[i.first] = i.second;
        dfs(i.first, n, d + 1);
    }
}
    
int main(){
    int t;
    for(cin >> t; t; t--){
        int ans = 0;
        
        for(int i = 0; i <= n; i++){
            dep[i].clear();
            con[i].clear();
        }

        cin >> n >> D;
        D <<= 1;
        for(int i = 0; i < n - 1; i++){
            int s, l, c;
            cin >> s >> l >> c;
            c <<= 1;
            con[s].push_back({l, c});
            con[l].push_back({s, c});
        }

        for(int i = 1; i <= n; i++){
            if(con[i].size()){
                maxh = 0;
                dfs(i, 0, 0);
                break;
            }
        }

        for(; maxh > -1; maxh--){
            for(int i : dep[maxh]){
                int mx1 = 0, mx2 = 0;
                for(auto next : con[i]){
                    if(par[i] == next.first)
                        continue;
                    if(mx1 < tree[next.first]){
                        mx2 = mx1;
                        mx1 = tree[next.first];
                    }
                    else
                        mx2 = max(mx2, tree[next.first]);
                }
                if(mx2 < D / 2){
                    int cost = max(0, mx1 + mx2 - D);
                    ans += cost;

                    tree[i] = parv[i] + mx1 - cost;
                }
                else{
                    for(auto next : con[i]){
                        if(next.first == par[i])
                            continue;
                        ans += max(0, tree[next.first] - D / 2);
                    }
                    tree[i] = parv[i] + D / 2;
                }
            }
        }

        cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    }

    return 0;
}
