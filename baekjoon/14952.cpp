#include<iostream>
#include<cmath>

using namespace std;

int D[5000000], ans, a, b, x;
int board[5][5], dir[4][4] = {0, 1, 0, -1,
                            1, 1, -1, -1,
                            1, 0, -1, 0,
                            -1, 1, 1, -1};

int dy() {
    int index = 0, ret = 0;
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            ret += pow(3, board[j][i]);
        }
    }

    return ret;
}

void check() {

}

void dfs(int player) {
    check();

    for(int i = 1; i <= 4; i++) {
        for(int j = 4; j > 0 && !board[j][i]; j--){
            if(j) {
                board[j][i] = player;
                if(!dy()) dfs((player == 1 ? 2 : 1));
                board[j][i] = 0;
            }
        }
    }
}


int main(){

}
