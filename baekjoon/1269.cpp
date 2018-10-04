#include<bits/stdc++.h>

using namespace std;

set<int> a;
int n, m, share;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.insert(num);
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if(a.find(num) != a.end()) share++;
    }

    cout << n + m - 2 * share << '\n';
}
