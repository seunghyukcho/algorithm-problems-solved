#include <iostream>
#include <string>

using namespace std;

static int N, M, map[502][502], ans;

int main()
{
    string s;
    cin >> N >> M;

    for(int i = 0; i < N; i++) 
    {
        cin >> s;
        for(int j = 0; j < M; j++) map[i][j] = s[j] - '0';
    }

    for(int i = 0; i < N / 2; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int here = map[i][j], next = map[N - i - 1][M - j - 1];

            if(here == 8 && next == 8) ans += 0;
            else if(here * next == 54) ans += 0;
            else if(here == 6 && next == 6) ans += 1;
            else if(here == 9 && next == 9) ans += 1;
            else if(here == 7 && next == 7) ans += 1;
            else
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if(N % 2)
    {
        for(int i = 0; i < M / 2; i++)
        {
            int here = map[N / 2][i], next = map[N / 2][M - 1 - i];

            if(here == 8 && next == 8) ans += 0;
            else if(here * next == 54) ans += 0;
            else if(here == 6 && next == 6) ans += 1;
            else if(here == 9 && next == 9) ans += 1;
            else if(here == 7 && next == 7) ans += 1;
            else
            {
                cout << -1 << '\n';
                return 0;
            }
        }

        if(M % 2 && map[N / 2][M / 2] != 8)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';

    return 0;
}