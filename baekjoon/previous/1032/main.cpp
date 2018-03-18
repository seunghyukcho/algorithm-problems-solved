#include<iostream>
#include<string>

using namespace std;

int main(){
    char s[53][53];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%s", &s[i]);
    }
    for(int i = 0; s[0][i] != NULL; i++){
        char ch = s[0][i];
        int flag = 0;
        for(int j = 1; j < n; j++){
            if(s[j][i] != ch){
                flag++;
                break;
            }
        }
        if(flag)cout << '?';
        else cout << ch;
    }
    cout << '\n';

    return 0;
}
