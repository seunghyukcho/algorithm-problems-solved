#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;
    int pos = -1, st = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == ')' && !st)
        {
            pos = i;
            break;
        }
        else if(s[i] == ')') st--;
        else st++;
    }

    if(pos == -1)
    {
        cout << (st ? "No\n" : "Yes\n");
        return 0;
    }

    st = 0;
    for(int i = pos + 1; i < n; i++)
    {
        if(s[i] == ')' && !st)
        {
            cout << "No\n";
            return 0;
        }
        else if(s[i] == ')') st--;
        else st++;
    }

    if(st == 1)
    {
        cout << "Yes\n";
    }
    else cout << "No\n";

    return 0;
}