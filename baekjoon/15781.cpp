#include<iostream>

using namespace std;

long long mx[2];
int n, m, num;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> num;
        mx[0] = mx[0] < num ? num : mx[0];
    }

    for(int i = 0; i < m; i++) {
        cin >> num;
        mx[1] = mx[1] < num ? num : mx[1];
    }

    cout << mx[0] + mx[1] << '\n';

    return 0;
}
