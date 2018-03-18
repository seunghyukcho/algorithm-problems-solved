#include<iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    int n = 1;
    int ans1, ans2;

    while(n * (n + 1) / 2 < x)n++;
    x -= n * (n - 1) / 2;
    if(n % 2 == 0){
        ans1 = x;
        ans2 = n - x + 1;
    }
    else{
        ans1 = n - x + 1;
        ans2 = x;
    }
    
    cout << ans1 << '/' << ans2 << '\n';

    return 0;
}
