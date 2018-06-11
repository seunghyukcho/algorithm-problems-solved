#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;

    cin >> s;
    for(int i = 1; i < s.size() - 1; i++){
        int check = (s[i - 1] - 'A' + 1) * (s[i] - 'A' + 1) * (s[i + 1] - 'A' + 1);

        if(check == 6){
            cout << "Yes\n";

            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
