#include<iostream>
#include<string>

using namespace std;

string val;
int D[5002];
int r = 1e6;

int dy(int n){
    if(n > val.size())
        return 0;
    if(n == val.size())
        return 1;
    if(D[n])
        return D[n];

    if(val[n] >= '1' && val[n] <= '9')
        D[n] = ((D[n] % r) + (dy(n + 1) % r)) % r;
    if(val[n] == '1' && (n + 1 < val.size() && val[n + 1] >= '0' && val[n + 1] <= '9'))
        D[n] = ((D[n] % r) + (dy(n + 2) % r)) % r;
    else if(val[n] == '2' && (n + 1 < val.size() && val[n + 1] <= '6' && val[n + 1] >= '0'))
        D[n] = ((D[n] % r) + (dy(n + 2) % r)) % r;

    return D[n];
}

int main(){
    cin >> val;

    cout << dy(0) << '\n';

    return 0;
}
