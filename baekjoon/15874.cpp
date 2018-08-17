#include<iostream>
#include<string>

using namespace std;

int n, k;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    getline(cin, s, '\n');
    getline(cin, s, '\n');

    for(auto& ch : s) {
        if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + k) % ('Z' - 'A' + 1) + 'A';
        } else if(ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + k) % ('Z' - 'A' + 1) + 'a';
        }
    }

    cout << s << '\n';

    return 0;
}
