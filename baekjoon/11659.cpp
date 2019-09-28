#include <iostream>
#include <algorithm>

using namespace std;

static int sum[100002], n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    for(int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;

        if(e < s) swap(s, e);
        cout << sum[e] - sum[s - 1] << '\n';
    }
}