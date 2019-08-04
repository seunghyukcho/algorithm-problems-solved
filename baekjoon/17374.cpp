#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int p,q,a,b,c,d;
        cin >> p>>q>>a>>b>>c>>d;
        int r = q/c*d;
        int t = (p-r)/(a+b);
        p -= a*t;
        r += b*t;
        int p_ = p-a;
        int r_ = r+b;
        int p__ = p+a;
        int r__ = r-b;
        cout << max(max(min(p,r),min(p_,r_)),min(p__,r__)) << '\n';
    }
    return 0;
}