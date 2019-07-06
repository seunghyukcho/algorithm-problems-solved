#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll ans = 0;
int n;

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i < n;)
    {
    	int m = (n - 1) / i;

    	int l1 = (n - 1) / m;
    	int l2 = ceil(n / (double)(m + 1));
    	ans += (l1 - l2 + 1) * (ll)(m + 1);
    	
    	i = l1 + 1;
    }
    
    cout << ans + 1 << '\n';
}