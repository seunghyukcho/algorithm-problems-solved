#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        int cat = 0;
        
        for(auto i = s.begin(); i < s.end(); i++){
            if(*i == '(')cat++;
            else{
                if(cat == 0){
                    cat--;
                    break;
                }
                else cat--;
            }
        }

        if(cat == 0)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}

