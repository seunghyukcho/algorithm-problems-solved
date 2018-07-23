#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

struct Node {
    int date, idx, change;
} N[100002];

bool comp(Node n1, Node n2) { return n1.date < n2.date; }
map<int, int> G;
map<int, int> cow;

int n, g;
int main(){
    ios::sync_with_stdio(false);

    cin >> n >> g;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> N[i].date >> N[i].idx >> s;
        N[i].change = stoi(s);

        cow[N[i].idx] = g;
    }
    G[g] = 1000000000;

    sort(N, N + n, comp);
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int& here = cow[N[i].idx];

        bool wastop = here == G.rbegin()->first;
        int wascnt = G.rbegin()->second;

        G[here]--;
        if(G[here] == 0) G.erase(here);

        here += N[i].change;
        G[here]++;

        bool istop = here == G.rbegin()->first;
        int iscnt = G.rbegin()->second;

        if(wastop) {
            if(!istop || wascnt != 1 || iscnt != 1) ans++;
        } else if(istop){
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
