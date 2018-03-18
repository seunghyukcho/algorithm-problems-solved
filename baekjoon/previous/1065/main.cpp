#include<iostream>

using namespace std;

int ans;

void d(int n){
    if(n == 0)return;
    int min, k, flag;
    min = (n % 10) - ((n / 10) % 10);
    k = n;
    flag = 0;
    while(k / 10 != 0){
        int m = (k % 10) - ((k / 10) % 10);
        if(m != min){
            flag++;
            break;
        }
        k /= 10;
    }
    if(!flag)ans++;
    d(n - 1);
}

int main(){
    int n;
    cin >> n;
    d(n);
    cout << ans << '\n';

    return 0;
}
