#include<iostream>
#include<cmath>

using namespace std;

long long a, b, v;

int main(){
    cin >> a >> b >> v;

    long long limit = v - a;
    long long sleep = ceil(limit / (double)(a - b));

    cout << (sleep > 0 ? sleep : 0) + 1 << '\n';

    return 0;
}
