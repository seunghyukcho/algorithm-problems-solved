#include<iostream>

using namespace std;

long long count(long long n){
    long long ret = 0;

    for(; n > 0; n /= 2)
        if(n % 2)
            ret++;

    return ret;
}

int main(){
    long long t, n;

    for(cin >> t; t > 0; t--){
        cin >> n;

        cout << count(n ^ (n - 1)) << '\n';
    }

    return 0;
}
