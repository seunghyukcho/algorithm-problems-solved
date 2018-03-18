#include<iostream>
#include<string>

using namespace std;

int rev(int num, int ten){
    int nnum = 0;
    ten /= 10;
    while(num > 0){
        nnum += (num % 10) * ten;
        ten /= 10;
        num /= 10;
    }

    return nnum;
}

int main(){
    string s;
    int num = 0;
    int ans = 0, tenth = 1;
    int sign = 1;
    cin >> s;
    for(auto i = s.begin(); i != s.end(); i++){
        char ch = *i;
        if(ch == '+'){
            ans += sign * rev(num, tenth);
            num = 0;
            tenth = 1;
        }
        else if(ch == '-'){
            ans += sign * rev(num, tenth);
            sign = -1;
            num = 0;
            tenth = 1;
        }
        else{
            num += tenth * (ch - '0');
            tenth *= 10;
        }
    }
    
    ans += sign * rev(num, tenth);
    cout << ans << '\n';

    return 0;
}
