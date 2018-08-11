#include<iostream>
#include<string>

using namespace std;

string p, s;
int f[4];

void failure_function() {
    for(int i = 0; i < p.size(); i++) f[i] = 0;

    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = f[j - 1];

        if(p[i] == p[j]) f[i] = ++j;
    }
}

int kmp() {
    int ret = 0, j = 0;

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
    getline(cin, s, '\n');

    p = ":-)";
    failure_function();
    int smile = kmp();

    p = ":-(";
    failure_function();
    int shy = kmp();

    if(smile == shy) {
        if(smile == 0) cout << "none\n";
        else cout << "unsure\n";
    } else if(smile > shy) cout << "happy\n";
    else cout << "sad\n";

    return 0;
}
