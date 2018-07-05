#include <iostream>

using namespace std;

typedef long long ll;

ll P = 1000000007;

ll fac[200010];

void get_fac()
{
    fac[0] = 1;
    fac[1] = 1;

    for(int i = 2; i < 200010; i++)
    {
        fac[i] = (fac[i - 1] * i) % P;
    }
}

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

int main()
{
    get_fac();

    int N;
    int no = 0;
    for(int i = 1; i <= N; i++)
    {
        int A;
        cin >> A;
        if(no == 0) no += max(0, N - i - A);
    }

    cout << (fac[N] - (no * fac[N-1]) % P + P) % P;

    return 0;

}
