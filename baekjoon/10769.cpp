#include<bits/stdc++.h>

using namespace std;

vector<int> failure_function(string p) {
    vector<int> f(p.size() + 1);
    for(int i = 0; i < p.size(); i++) f[i] = 0;

    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = f[j - 1];

        if(p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

int kmp(string s, string p) {
    int ret = 0, j = 0;
    vector<int> f = failure_function(p);

    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != p[j]) j = f[j - 1];

        if(s[i] == p[j]) {
            if(j == p.size() - 1) {
                ret++;
                j = f[j];
            } else j++;
        }
    }

    return ret;
}

int main(){
    string s, p;
    getline(cin, s, '\n');

    p = ":-)";
    int smile = kmp(s, p);

    p = ":-(";
    int shy = kmp(s, p);

    if(smile == shy) {
        if(smile == 0) cout << "none\n";
        else cout << "unsure\n";
    } else if(smile > shy) cout << "happy\n";
    else cout << "sad\n";

    return 0;
}
