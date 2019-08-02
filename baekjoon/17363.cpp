#include <iostream>
#include <map>

using namespace std;

char ans[102][102];

int main()
{
    map<char, char> conv;
    int n, m;

    cin >> n >> m;
    
    conv['.'] = '.';
    conv['O'] = 'O';
    conv['-'] = '|';
    conv['|'] = '-';
    conv['/'] = '\\';
    conv['\\'] = '/';
    conv['^'] = '<';
    conv['<'] = 'v';
    conv['v'] = '>';
    conv['>'] = '^';

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char ch;
            cin >> ch;

            ans[m - 1 - j][i] = conv[ch];
        }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++) cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}