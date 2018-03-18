#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long min, max;
    cin >> min >> max;
    long long seg = max - min + 1;
    long long ans = seg;
    vector<bool> prime(1e6 + 1, true);
    vector<bool> check(seg, true);
    for(long long i = 2; i * i <= max; i++){
        if(prime[i]){
            long long num;
            if(min % (i * i) == 0)num = min;
            else num = min + (i * i) - min % (i * i);
            for(;num <= max; num += i * i){
                if(check[num - min])ans--;
                check[num - min] = false;
            }
            for(long long j = i; j * j <= max; j += i)prime[j] = false;
        }
    }

    cout << ans << '\n';

    return 0;
}
