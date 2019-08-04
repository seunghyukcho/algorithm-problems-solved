#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll gcd(ll a, ll b)
{   
    if(a<0) a = -a;
    if(b<0) b = -b;
    return (b>0?gcd(b,a%b):a);
}
ll pow(ll a, ll b)
{
    if(b == 0) return 1;

    ll ret = pow(a, b / 2);
    ll ans = ret * ret % MOD;
    if(b % 2) ans = ans * a % MOD;
    return ans;
}
struct gong
{
    ll a, r;
} g[300000];

ll integ(ll b1, ll b2, ll r, ll a)
{
    ll d1 = b1-a;
    ll d2 = b2-a;
    return (b2-b1)*r*r-(pow(d2,3)-pow(d1,3))/3;
}

bool comp(gong g1, gong g2)
{
    return (g1.a-g1.r)<(g2.a-g2.r);
}

int main()
{
    //cout << pow(2,MOD-2);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll a, r;
        cin >> a >> r;
        g[i].a = 3*a;
        g[i].r = 3*r;
    }
    
    sort(g, g+n, comp);
    ll right = -2000000;
    ll a;
    ll r;
    ll answer = 0;

    for(int i = 0; i < n; i++)
    {
        ll na = g[i].a;
        ll nr = g[i].r;
        ll nright = na+nr;
        if(nright<=right) continue;
        ll nleft = na-nr;
        if(right <= nleft)
        {
            answer = answer + integ(nleft, nright, nr, na);
        }
        else
        {
            ll c = (r*r-nr*nr-a*a+na*na)/(na+na-a-a);
            answer = answer - integ(c, right, r, a);
            answer = answer + integ(c, nright, nr, na);
        }
        a = na;
        r = nr;
        right = nright;
        answer = answer % MOD;
    }

    cout << (answer*pow(27,MOD-2))%MOD << endl;
}