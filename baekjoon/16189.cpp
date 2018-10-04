#include<bits/stdc++.h>

using namespace std;

string s;
int k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> k;
    for(int i = 0; i < s.size() / 2; i++) {
        int next = s.size() - 1 - i;
        if(s[i] != s[next]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
