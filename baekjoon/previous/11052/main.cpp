#include<iostream>

using namespace std;

int D[1002];
int val[1002];

int dy(int n){
    if(n == 0)
        return 0;
    if(D[n])
        return D[n];

    int ret = 0;
    for(int i = 1; i <= n; i++)
        ret = max(ret, dy(n - i) + val[i]);

    return D[n] = ret;
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> val[i];

    cout << dy(n) << '\n';

    return 0;
}
