#include<iostream>

using namespace std;

int ans[200002];
int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int page = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        page += num;
        ans[i] = page / m;
        page %= m;

        cout << ans[i] << ' ';
    }

    cout << '\n';

    return 0;

}
