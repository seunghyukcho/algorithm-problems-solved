#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        int ans = 0;
        cin >> s;
        int flag = 1;
        for(auto i = s.begin(); i < s.end(); i++){
            if(*i == 'O'){
                ans += flag++;
            }
            else flag = 1;
        }
        cout << ans << '\n';
    }

    return 0;
}

