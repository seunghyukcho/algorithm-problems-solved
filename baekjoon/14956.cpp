#include<iostream>

using namespace std;

int n, k;

int dir[4][2] = {0, 0, 1, 0, 0, -1, 1, -1};
int dir2[4][4] = {2, 3, 1, 0, 2, 0, 1, 3, 1, 0, 2, 3, 1, 3, 2, 0};
int dir3[4][4] = {1, 0, 0, 3, 0, 1, 1, 2, 3, 2, 2, 1, 2, 3, 3, 0};

void f(int x, int y, int size, int step, int pos) {
    //cout << x << ' ' << y << ' ' << pos << '\n';
    if(size == 1) {
        printf("%d %d\n", x, y);
        return;
    }

    int unit = (size * size) / 4;
    for(int i = 1; i <= 4; i++) {
        if(k < step + unit * i) {
            //cout << dir2[pos][i - 1] << ' ' << dir3[pos][i - 1] << '\n';
            f(x + (size / 2) * dir[dir2[pos][i - 1]][0], y + (size / 2) * dir[dir2[pos][i - 1]][1], size / 2, step + unit * (i - 1), dir3[pos][i - 1]);
            break;
        }
    }
}

int main(){
    cin >> n >> k;
    f(1, n, n, 1, 1);

    return 0;
}
