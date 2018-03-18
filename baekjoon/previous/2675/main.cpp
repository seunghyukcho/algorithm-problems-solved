#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int num;
        cin >> num >> s;
        for(auto j = s.begin(); j < s.end(); j++){
            for(int k = 0; k < num; k++)cout << *j;
        }
        cout << '\n';
    }

    return 0;
}
