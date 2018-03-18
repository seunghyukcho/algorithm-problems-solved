#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(auto i = s.begin(); i < s.end(); i++){
        if(*i >= 'W')ans += 9;
        else if(*i >= 'T')ans += 8;
        else if(*i >= 'P')ans += 7;
        else if(*i >= 'M')ans += 6;
        else if(*i >= 'J')ans += 5;
        else if(*i >= 'G')ans += 4;
        else if(*i >= 'D')ans += 3;
        else ans += 2;

        ans += 1;
    }
    

    cout << ans << '\n';

    return 0;
}
