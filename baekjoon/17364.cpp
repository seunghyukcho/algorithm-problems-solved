#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Duration
{
    int s, e;
} D[100002];

bool operator<(Duration d1, Duration d2)
{
    return d1.e == d2.e ? d1.s > d2.s : d1.e < d2.e;
}

int N, K, last, ans;

int main()
{
    multiset<int> st;

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> D[i].s >> D[i].e;
    sort(D, D + N);

    for(int i = 1; i < K; i++) st.insert(0);
    for(int i = 0; i < N; i++)
    {
        if(last < D[i].s)
        {
            if(K > 1) 
            {
                auto f = upper_bound(st.begin(), st.end(), -D[i].s);
                if(f != st.end())
                {
                    st.erase(*f);
                    st.insert(-D[i].e);
                }
                else
                {
                    ans++;
                    last = D[i].e;
                }
            }
            else
            {
                ans++;
                last = D[i].e;
            }
        }
    }

    cout << ans << '\n';
}