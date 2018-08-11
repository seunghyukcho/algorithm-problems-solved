#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s, p;
int f[1000002];

void failure_function() {
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = f[j - 1];

        if(p[i] == p[j]) f[i] = ++j;
    }
}

vector<int> kmp() {
    vector<int> ret;

    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != p[j]) j = f[j - 1];

        if(s[i] == p[j]) {
            if(j == p.size() - 1) {
                ret.push_back(i - p.size() + 2);
                j = f[j];
            } else j++;
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);

    getline(cin, s, '\n');
    getline(cin, p, '\n');

    failure_function();
    vector<int> ans = kmp();

    cout << ans.size() << '\n';
    for(int answer : ans) cout << answer << '\n';

    return 0;
}
