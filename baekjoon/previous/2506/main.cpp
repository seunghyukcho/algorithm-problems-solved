#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int flag = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num)ans += flag++;
        else flag = 1;
    }

    cout << ans << '\n';

    return 0;
}
