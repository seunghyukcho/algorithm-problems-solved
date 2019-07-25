#include<iostream>
#include<string>

using namespace std;

string s;
string s1, s2, ans;

int main(){
    cin >> s;

    for(auto ch : s) {
        if(ch == '1') s1 += '1';
        else if(ch == '0' || ch == '2') s2 += ch;
    }

    int i;
    for(i = 0; i < s.size() && s2[i] == '0'; i++) {
        ans += s2[i];
    }

    ans += s1;
    for(; i < s2.size(); i++) {
        ans += s2[i];
    }

    cout << ans << '\n';

    return 0;
}
