#include<iostream>
#include<string>

using namespace std;

int t, k;
string s;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int ans = 0;
        cin >> s >> k;

        for(int i = 0; i <= s.size() - k; i++){
            if(s[i] == '-'){
                ans++;
                for(int j = i; j < i + k; j++)
                    s[j] = (s[j] == '-' ? '+' : '-');
            }
        }

        bool check = true;
        for(int i = s.size() - k + 1; i < s.size(); i++)
            if(s[i] == '-'){
                check = false;
                break;
            }
        cout << "Case #" << cs << ": ";
        if(check)
            cout << ans << '\n';
        else
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}
                
