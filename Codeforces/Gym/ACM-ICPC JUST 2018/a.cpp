#include<iostream>
#include<map>

using namespace std;

int t, n, q, a[100002], op, p, v;
map<int, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> t; t > 0; t--) {
        int ans = 0;
        m.clear();

        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(m[a[i]] == 0) ans++;
            m[a[i]]++;
        }

        for(int i = 1; i <= q; i++) {
            cin >> op;

            if(op == 1) {
                cin >> p >> v;
                m[a[p]]--;

                if(m[a[p]] == 0) ans--;
                if(m[v] == 0) ans++;

                m[v]++;
                a[p] = v;
            } else {
                cout << ans - (m[0] ? 1 : 0) << '\n';
            }
        }
    }

    return 0;
}
