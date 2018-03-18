#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int ans = 0;

    for(auto i = s.begin(); i < s.end(); i++){
        int num;
        if(*i >= '0' && *i <= '9')num = *i - '0';
        else num = *i - 'A' + 10;

        ans += num * pow(16, i - s.begin());
    }

    cout << ans << '\n';

    return 0;
}
        
