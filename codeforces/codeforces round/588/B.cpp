#include <iostream>
#include <string>

using namespace std;

static int n, k;
static string s;

int main()
{
    cin >> n >> k >> s;
    if(n == 1 && k) cout << 0 << '\n';
    else
    {
        for(int i = 0; i < n && k; i++)
        {
            if(i == 0 && s[i] != '1')
            {
                s[i] = '1';
                k--;
            }
            else if(i != 0 && s[i] != '0')
            {
                s[i] = '0';
                k--;
            }
        }

        cout << s << '\n';
    }
}