#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<bool> check(200, false);
        string s;
        cin >> s;
        int flag = 0;
        for(auto j = s.begin(); j < s.end(); j++){
            char ch = *j;
            if(check[ch]){
                flag++;
                break;
            }
            else{
                check[ch] = true;
                while(j < s.end() && *j == ch)j++;
                j--;
            }
        }
        if(!flag)ans++;
    }

    cout << ans << '\n';

    return 0;
}
