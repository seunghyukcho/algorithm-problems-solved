#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<int, int> m;

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> D[i].s >> D[i].e;
    sort(D, D + N);

    for(int i = 1; i < K; i++) m[0]++;
    for(int i = 0; i < N; i++)
    {
        if(last < D[i].s)
        {
            auto f = m.upper_bound(-D[i].s);
            if(f != m.end())
            {
                m[-D[i].e]++;
                m[f->first]--;
                if(m[f->first] == 0) m.erase(f);
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