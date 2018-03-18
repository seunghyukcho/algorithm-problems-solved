#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int length = s1.size();
        int ans = 0;
        for(int j = 0; j < length; j++){
            if(*(s1.begin() + j) != *(s2.begin() + j))ans++;
        }
        cout << "Hamming distance is " << ans << ".\n";
    }
    
    return 0;
};
