#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long long pow(int num, int p){
    long long ret = 1;
    for(int i = 0; i < p; i++)
        ret *= num;

    return ret;
}

int main(){
    long long ans = 0;
    string n;
    int b;
    
    cin >> n >> b;
    reverse(n.begin(), n.end());

    for(int i = 0; i < n.size(); i++){
        char ch = n[i];

        if(ch >= '0' && ch <= '9')
            ans += (ch - '0') * pow(b, i);
        else
            ans += (ch - 'A' + 10) * pow(b, i);
    }

    cout << ans << '\n';

    return 0;
}

