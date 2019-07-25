#include<iostream>
#include<string>

using namespace std;

int psum[1002], n, m, q;
string s, t;

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m >> q >> s >> t;
    for(int i = 0; i + t.size() <= s.size(); i++) {
        bool check = true;

        for(int j = 0; j < t.size() && check; j++)
            if(t[j] != s[i + j]) check = false;

        if(check) psum[i + 1] = 1;
        psum[i + 1] += psum[i];
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if(l + t.size() - 1 > r) cout << 0 << '\n';
        else {
            r -= t.size() - 1;

            cout << psum[r] - psum[l - 1] << '\n';
        }
    }

    return 0;
}
