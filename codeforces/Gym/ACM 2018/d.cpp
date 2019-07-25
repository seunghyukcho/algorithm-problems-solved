#include <iostream>

using namespace std;

long long int min(long long int a, long long int b);

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        long long int n, m;
        cin >> n >> m;
        if(n%2 == 0 && m%2 == 0) cout << min((n+1)*m/2, (m+1)*n/2);
        else if(n % 2 == 0) cout << min((n+1)*m/2 + n/2, (m+1)*n/2);
        else if(m % 2 == 0) cout << min((m+1)*n/2 + m/2, (n+1)*m/2);
        else cout << min((n/2+1)*m, (m/2+1)*n);

        cout << endl;
    }
    return 0;
}



long long int min(long long int a, long long int b)
{
    return (a < b) ? a : b;
}
