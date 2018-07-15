#include<iostream>
#include<vector>

using namespace std;

long long result = 0;
vector<int> child[500002];
int n;

void sum(int here, int prev, int level) {
    bool check = true;
    for(int next : child[here]) {
        if(next == prev) continue;
        sum(next, here, level + 1);
        check = false;
    }

    if(check) result += level;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        child[s].push_back(e);
        child[e].push_back(s);
    }

    sum(1, 1, 0);

    //cout << result << '\n';
    cout << (result % 2 ? "Yes\n" : "No\n");

    return 0;
}
