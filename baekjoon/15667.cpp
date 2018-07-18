#include<iostream>

using namespace std;

int fire(int x) {
    return x * x + x + 1;
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) if(fire(i) == n) {
        cout << i << '\n';
        break;
    }

    return 0;
}
