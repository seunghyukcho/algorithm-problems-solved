#include <iostream>

using namespace std;

typedef long long ll;

ll P = 1000000007;

int A, B;

ll pow(ll a, ll b)
{
    ll r = 1;
    while(b > 0)
    {
        if(b % 2)
        {
            r *= a;
            r %= P;
        }
        a *= a;
        a %= P;
        b /= 2;
    }
    return r % P;
}

ll price(ll x, ll y, ll m)
{
    ll k = pow(A, (x - y)) * pow(B, y - 1);
    k %= P;
    ll s;
    if(A > B)
    {
        ll C = pow((A - B), P - 2);
        ll D = (pow(A, m+1) - 1) * pow((A-1), P - 2);
        D %= P;
        ll E = (pow(B, m+1) - 1) * pow((B-1), P - 2);
        E %= P;
        s = (C * ((D - E + P) % P)) % P;
    }
    else if(A < B)
    {
        ll C = pow((B - A), P - 2);
        ll D = (pow(A, m+1) - 1) * pow((A-1), P - 2);
        D %= P;
        ll E = (pow(B, m+1) - 1) * pow((B-1), P - 2);
        E %= P;
        s = (C * ((E - D + P) % P)) % P;
    }
    else
    {
        if(A == 1)
        {
            s = (m % P) * ((m + 1) % P);
            s %= P;
            s *= pow(2, P - 2);
            s %= P;
        }
        else
        {
            ll C = pow((A - 1), P - 2);
            C %= P;
            ll D = (m % P) * pow(A, m);
            D %= P;
            ll E = (pow(A, m) - 1) * pow((A-1), P - 2);
            E %= P;
            s = C * ((D - E + P) % P);
            s %= P;
        }
    }
    ll r = k * s;
    return r % P;
}

int main()
{
    scanf("%d%d", &A, &B);

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        ll x, y, m;
        scanf("%lld%lld%lld", &x, &y, &m);
        printf("%lld\n", price(x, y, m));
    }

    return 0;
}
