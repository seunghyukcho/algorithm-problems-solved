#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    string s1, s2 = "";
    int ans = 0;
    while(getline(cin, s1)){
        s2.append(s1);
    }

    istringstream sin(s2);

    while(getline(sin, s1, ',')){
        ans += stoi(s1);
    }

    cout << ans << '\n';

    return 0;
}
