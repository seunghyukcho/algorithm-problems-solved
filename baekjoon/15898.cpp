#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Bomb
{
    int value[4][4];
    int letter[4][4];
} B[12];

int n, board1[5][5], ans;
char board2[5][5];

void solve()
{
    int cnt[4] = { 0, 0, 0, 0 };
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
        {
            if(board2[i][j] == 'R') cnt[0] += board1[i][j];
            if(board2[i][j] == 'B') cnt[1] += board1[i][j];
            if(board2[i][j] == 'G') cnt[2] += board1[i][j];
            if(board2[i][j] == 'Y') cnt[3] += board1[i][j];
        }

    ans = max(ans, 7 * cnt[0] + 5 * cnt[1] + 3 * cnt[2] + 2 * cnt[3]);
}

void putBomb(int idx, int dir, int pos)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            int nextx = i, nexty = j;
            for(int k = 0; k < dir; k++)
            {
                int tmp = nextx;
                nextx = nexty, nexty = 3 - tmp;
            }

            nextx += pos / 2, nexty += pos % 2;
            int& val = board1[nextx][nexty];

            val += B[idx].value[i][j];
            val = max(val, 0);
            val = min(val, 9);
            if(B[idx].letter[i][j] != 'W') board2[nextx][nexty] = B[idx].letter[i][j];
        }
}

void putBombs(vector<int> bombs, vector<int> dirs, vector<int> pos)
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) board1[i][j] = 0, board2[i][j] = 'W';
    
    for(int k = 0; k < 3; k++) putBomb(bombs[k], dirs[k], pos[k]);
    solve();
}

void selectPos(vector<int> bombs, vector<int> dirs)
{
    vector<int> pos(3);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
            {
                pos[0] = i, pos[1] = j, pos[2] = k;
                putBombs(bombs, dirs, pos); 
            }
}

void selectDirs(vector<int> bombs)
{
    vector<int> dirs(3);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
            {
                dirs[0] = i, dirs[1] = j, dirs[2] = k;
                selectPos(bombs, dirs); 
            }
}

void enumerateBombs(vector<int> v)
{
    for(int i = 0; i < 6; i++)
    {
        selectDirs(v);
        next_permutation(v.begin(), v.end());
    }
}

void selectBombs()
{
    vector<int> bombs(3);

    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
            for(int k = j + 1; k < n; k++)
            {
                bombs[0] = i, bombs[1] = j, bombs[2] = k;
                enumerateBombs(bombs);
            }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int x = 0; x < 4; x++)
            for(int y = 0; y < 4; y++) cin >> B[i].value[x][y];
        for(int x = 0; x < 4; x++)
            for(int y = 0; y < 4; y++) 
            {
                char ch;
                cin >> ch;
                B[i].letter[x][y] = ch;
            }
    }

    selectBombs();
    cout << ans << '\n';
}