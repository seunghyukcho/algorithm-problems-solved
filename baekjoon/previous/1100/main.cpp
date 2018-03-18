#include<iostream>
#include<string>

using namespace std;

int main(){
    int ans = 0;
    for(int i = 1; i < 9; i++){
        string s;
        cin >> s;
        for(auto j = s.begin(); j < s.end(); j++){
            if(*j == 'F'){
                if((j - s.begin() + 1) % 2 == i % 2)ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
    
