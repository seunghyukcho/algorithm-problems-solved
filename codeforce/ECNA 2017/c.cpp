#include<iostream>

using namespace std;

string s;

int main(){
    cin >> s;

    int sz = s.size() / 2, sum1 = 0, sum2 = 0;
    for(int i = 0; i < sz; i++) {
        sum1 += s[i] - 'A';
        sum2 += s[i + sz] - 'A';
    }
    for(int i = 0; i < sz; i++) {
        s[i] = (s[i] - 'A' + sum1 + sum2 + s[i + sz] - 'A') % 26 + 'A';
        cout << s[i];
    }

    cout << '\n';

    return 0;
}
