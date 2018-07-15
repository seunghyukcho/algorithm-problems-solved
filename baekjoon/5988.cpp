#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    string s;

    for(cin >> n; n > 0; n--) {
        cin >> s;
        if((s.back() - '0') % 2) cout << "odd\n";
        else cout << "even\n";
    }

    return 0;
}
