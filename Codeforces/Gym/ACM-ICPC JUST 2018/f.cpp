#include<iostream>
#include<string>

using namespace std;

int t, n, m;

int convert(string s) {
    return 60 * (10 * (s[0] - '0') + (s[1] - '0')) + 10 * (s[3] - '0') + s[4] - '0';
}

int main(){
    for(cin >> t; t > 0; t--) {
        string start, end;
        cin >> n >> m;

        int total = 0;
        for(int i = 0; i < n; i++) {
            cin >> start >> end;
            total += convert(end) - convert(start);
        }

        cout << (total >= m * 60 ? "YES\n" : "NO\n");
    }

    return 0;
}
