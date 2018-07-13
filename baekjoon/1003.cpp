#include<iostream>

using namespace std;

pair<int, int> D[42];
int t, n;
pair<int, int> fibo(int n) {
    if(n == 0) return make_pair(1, 0);
    if(n == 1) return make_pair(0, 1);
    if(D[n].first != 0) return D[n];

    auto ret1 = fibo(n - 1);
    auto ret2 = fibo(n - 2);
    return D[n] = make_pair(ret1.first + ret2.first, ret1.second + ret2.second);
}

int main(){
    for(cin >> t; t > 0; t--) {
        cin >> n;
        auto ret = fibo(n);
        cout << ret.first << ' ' << ret.second << '\n';
    }

    return 0;
}
