#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

unsigned char prime[(1000 + 7) / 8];
int n, max_n, ans, num[102];

bool is_prime(int k){
    return prime[k >> 3] & (1 << (k & 7));
}

void not_prime(int k){
    prime[k >> 3] &= ~(1 << (k & 7));
}

void erathosthenes(){
    memset(prime, 255, sizeof(prime));
    prime[0] &= ~(1 << 1);

    for(int i = 2; i <= max_n; i++){
        if(is_prime(i)){
            for(int j = 2; i * j <= max_n; j++)
                not_prime(i * j);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        max_n = max(max_n, num[i]);
    }

    erathosthenes();
    for(int i = 0; i < n; i++){
        if(is_prime(num[i]))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
