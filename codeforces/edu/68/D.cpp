#include <iostream>

using namespace std;

int t, n, k;

int main()
{
    for(cin >> t; t > 0; t--)
    {
        cin >> n >> k;
        if(n == 0) cout << "Bob\n";
        else if(k % 3 == 0)
        {
            n = n % (k + 1);
            cout << (n != k && n % 3 == 0 ? "Bob" : "Alice") << '\n';
        }
        else
            cout << (n % 3 == 0 ? "Bob" : "Alice") << '\n';   
    }
}