#include<iostream>
#include<string>

using namespace std;

string p = "I", s;
int n, m, f[1000002];

void failure_function() {
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j = f[j - 1];
        if(p[i] == p[j]) f[i] = ++j;
    }
}

int kmp() {
    int ret = 0, j = 0;

    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && p[j] != s[i]) j = f[j - 1];

        if(p[j] == s[i]) {
            if(j == p.size() - 1) {
                ret++;
                j = f[j];
            } else j++;
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> n >> m >> s;
    for(int i = 0; i < n; i++) p += "OI";

    failure_function();
    cout << kmp() << '\n';

    return 0;
}
