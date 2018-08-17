#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
vector<int> v(1, 0);

void int2bin(int n) {
    vector<int> ret;
    for(; n > 0; n /= 2) ret.push_back(n % 2);
    for(int i = ret.size() - 1; i >= 0; i--) v.push_back(ret[i]);
}

int main(){
    cin >> n >> k;

    for(int i = 0; v.size() < 500; i++) int2bin(i);

    for(int i = 0; i < 5; i++) cout << v[n * i + k - 1] << ' ';
    cout << '\n';

    return 0;
}
