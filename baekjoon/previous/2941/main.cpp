#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;

    for(auto i = s.begin(); i < s.end(); i++){
        if(*i == 'd' && (i+1) != s.end()){
            if(*(i+1) == 'z' && (i+2) != s.end() && *(i+2) == '=')i += 2;
            else if(*(i+1) == '-')i++;
        }
        else if((*i == 'c' || *i == 's' || *i == 'z')&& (i+1) != s.end()){
            if(*(i+1) == '-' || *(i+1) == '=')i++;
        }
        else if((*i == 'l' || *i == 'n') && (i+1) != s.end()){
            if(*(i+1) == 'j')i++;
        }
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
