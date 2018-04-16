#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int ans = 1e9, n;

void brute_force(int n, int k){
    if(n == 0)
        return;
    int check = sqrt(n);
    if(n == check * check){
        ans = min(ans, k);
        return;
    }

    for(long long i = 1; i < n; i *= 10){
        int l = n / i;
        int r = n % i;

        l = (l / 10) * i;
        if(l == 0 && i > 1 && r == n % (i / 10))
            continue;
        brute_force(l + r, k + 1);
    }
}

int main(){
    cin >> n;
    brute_force(n, 0);

    cout << (ans == 1e9 ? -1 : ans) << '\n';

    return 0;
}
