#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sum = 0;
    bool check = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0')check = true;
        sum += s[i] - '0';
    }

    if(sum % 3 || !check)cout << -1 << '\n';
    else{
        sort(s.begin(), s.end());
        for(int i = s.size() - 1; i >= 0; i--)cout << s[i];
        cout << '\n';
    }

    return 0;
}
