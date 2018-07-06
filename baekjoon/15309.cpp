#include<iostream>

using namespace std;

typedef long long ll;

ll A, B, N, x, y, m;
ll MOD = 1e9 + 7;

ll mod(ll a) {
    if(a < 0) a += MOD;
    return a % MOD;
}

ll mul(ll a, ll b) {
    return mod(mod(a) * mod(b));
}

ll pow(ll a, ll b) {
    if(b == 0) return 1;

    ll ret = pow(a, b / 2);
    ret = mul(ret, ret);
    if(b % 2) ret = mul(ret, a);

    return mod(ret);
}

ll inv(ll a, ll b) {
    return mul(mod(a), mod(pow(b, MOD - 2)));
}

ll f0() {
    return mul(pow(A, x - y), pow(B, y - 1));
}

ll f1() {
    if(A == 1) return inv(mul(m, m + 1), 2);
    else return mod(inv(mul(m, pow(A, m)), A - 1) - inv((pow(A, m) - 1), pow(A - 1, 2)));
}

ll f2() {
    ll left, right;

    if(A == 1) left = m + 1;
    else left = inv(pow(A, m + 1) - 1, A - 1);

    if(B == 1) right = m + 1;
    else right = inv(pow(B, m + 1) - 1, B - 1);

    return inv(left - right, A - B);
}

int main(){
    scanf("%lld%lld", &A, &B);

    for(scanf("%lld", &N); N > 0; N--) {
        ll ans;
        scanf("%lld%lld%lld", &x, &y, &m);

        if(A == B) ans = mul(f0(), f1());
        else ans = mul(f0(), f2());

        printf("%lld\n", ans);
    }

    return 0;
}
