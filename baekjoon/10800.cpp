#include<iostream>
#include<vector>

using namespace std;

struct Ball {
    int idx, color;
};

int n, C[200002], ans[200002];
vector<Ball> B[2002];

int main(){
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int sz, color;
        cin >> color >> sz;

        B[sz].push_back({i, color});
    }

    int total = 0;
    for(int i = 1; i <= 2000; i++) {
        for(auto here : B[i]) ans[here.idx] = total - C[here.color];

        for(auto here : B[i]) C[here.color] += i;
        total += i * B[i].size();
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';

    return 0;
}
