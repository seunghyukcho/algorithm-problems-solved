#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char, int> vowel;

int main(){
    vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = 1;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        //cout << s[i] << ' ' << vowel[s[i]] << '\n';
        if(s[i] == 'n') continue;
        if(!vowel[s[i]] && (i == s.size() - 1 || !vowel[s[i + 1]])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
