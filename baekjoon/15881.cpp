#include<iostream>
#include<string>

using namespace std;

int ans, n;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for(int i = 0; i + 3 < s.size(); i++) {
        if(s[i] == 'p' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'p') {
            ans++;
            i = i + 3;
        }
    }

    cout << ans << '\n';

    return 0;
}
