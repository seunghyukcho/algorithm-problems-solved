#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, p;
    bool ans = true;
    string s;

    cin >> n >> p;
    cin >> s;

    for(int i = 0; ans && i + p < n; i++){
        if(s[i] == s[i + p] && s[i] != '.')
            continue;
        else{
            ans = false;
            if(s[i] != '.')
                s[i + p] = 1 - s[i] + 2 * '0';
            else if(s[i + p] != '.')
                s[i] = 1 - s[i + p] + 2 * '0';
            else{
                s[i] = '1';
                s[i + p] = '0';
            }
        }
    }

    if(ans)
        cout << "No\n";
    else{
        for(auto ch : s){
            if(ch == '.')
                cout << '1';
            else
                cout << ch;
        }
        cout << '\n';
    }

    return 0;
}
