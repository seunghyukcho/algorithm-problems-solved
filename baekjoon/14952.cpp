#include<iostream>
#include<cmath>

using namespace std;

int a, b;
int board[4][4], dir[4][4] = {0, 1, 0, -1,
                            1, 1, -1, -1,
                            1, 0, -1, 0,
                            -1, 1, 1, -1};
int height[4] = {4, 4, 4, 4};
long long ans;
bool D[43046721];

int convert() {
    int ret = 0;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) ret += pow(3, i * 4 + j) * board[i][j];

    return ret;
}

int win(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int next[4] = {x + dir[i][0], y + dir[i][1], x + dir[i][2], y + dir[i][3]};

        bool check = true;
        for(int j = 0; j < 4 && check; j++) {
            if(next[j] < 0 || next[j] >= 4) check = false;
        }

        if(check) {
            if(board[x][y] == board[next[0]][next[1]] && board[x][y] == board[next[2]][next[3]]) return board[x][y];
        }
    }

    return 0;
}

int check(int x, int y) {
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++) {
            int result = win(i, j);

            if(result != 0) return result;
        }

    return 0;
}

void dfs(int x, int y, int player) {
    int here = convert();
    if(D[here]) return;
    D[here] = true;

    if(x == a && y == b) {
        if(check(x, y) == 2) ans++;
        return;
    }

    if(check(x, y) != 0) return;

    for(int i = 0; i < 4; i++) {
        if(height[i] > 0) {
            height[i]--;
            board[height[i]][i] = player;
            dfs(height[i], i, player % 2 + 1);
            board[height[i]++][i] = 0;
        }
    }
}

int main(){
    int x;
    cin >> x >> a >> b;
    a = 4 - a;
    b = b - 1;
    x--;

    board[3][x] = 1;
    height[x]--;
    dfs(3, x, 2);
    cout << ans << '\n';

    return 0;
}
