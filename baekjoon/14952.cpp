#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

<<<<<<< HEAD
long long D[pow(3, 16) - 1];
int x, a, b;

int dir[4][4] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
int board[4][4];

int convert() {
    int ret = 0;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) ret += pow(3, i + j) * board[i][j];
=======
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
>>>>>>> 7497ba700d70d1c7aca014b30fdd1cd82eac9cb0

    return 0;
}

<<<<<<< HEAD
bool row(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int next[4] = {x + dir[i][0], y + dir[i][1], x + dir[i][2], y + dir[i][3]};

        bool check = true;
        for(int j = 0; j < 4 && check; j++) {
            if(next[j] < 0 || next[j] > 4) check = false;
        }

        if(check) {
            if(board[next[0]][next[1]] == board[next[2][3]] && board[next[0]][next[1]] == board[x][y]) return true;
        }
    }

    return false;
}

bool check() {
    if(board[a][b] != 2) return false;

    board[a][b] = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) {
            if(board[i][j]) {
                if(row(i, j)) return false;
            }
=======
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
>>>>>>> 7497ba700d70d1c7aca014b30fdd1cd82eac9cb0
        }

    board[a][b] = 2;
    for(int i = a - 1; i <= a + 1; i++)
        for(int j = a - 1; j <= a + 1; j++) {
            if(i >= 0 && j >= 0 && i < 4 && j < 4) {
                if(row(i, j)) return true;
            }
        }

    return false;
}

<<<<<<< HEAD
int dfs(int player) {
    int here = convert();
    if(D[here]) return D[here];


    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!board[i][j]) {
                if(i == 3 || board[i + 1][j]) {
                    board[]
                }
            }
        }
    }
=======
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
>>>>>>> 7497ba700d70d1c7aca014b30fdd1cd82eac9cb0
}
