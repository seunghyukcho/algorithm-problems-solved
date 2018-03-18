#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    int ans = 0;
    while(getline(cin, s, ',')){
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
