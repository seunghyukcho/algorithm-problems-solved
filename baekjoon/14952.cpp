#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long D[pow(3, 16) - 1];
int x, a, b;

int dir[4][4] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
int board[4][4];

int convert() {
    int ret = 0;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) ret += pow(3, i + j) * board[i][j];

    return ret;
}

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
}
