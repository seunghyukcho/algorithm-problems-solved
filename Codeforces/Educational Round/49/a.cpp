#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int n, sz;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(cin >> n; n > 0; n--) {
        bool check = true;

        cin >> sz >> s;
        for(int i = 0; i < s.size() / 2 && check; i++) {
            int start = i, end = s.size() - 1 - i;

            if(!(abs(s[start] - s[end]) == 0 || abs(s[start] - s[end]) == 2)) check = false;
        }

        cout << (check ? "YES\n" : "NO\n");
    }

    return 0;
}
