#include<iostream>

using namespace std;

int n, r, c;
int dir[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
void divide(int x, int y, int size, int step) {
    if(x == r && y == c) {
        printf("%d\n", step);
        return;
    }

    int count = size * size / 4;
    for(int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0] * size / 2;
        int nexty = y + dir[i][1] * size / 2;

        if(r < nextx + size / 2 && c < nexty + size / 2) {
            divide(nextx, nexty, size / 2, step + count * i);
            return;
        }
    }
}

int main(){
    cin >> n >> r >> c;

    divide(0, 0, 1 << n, 0);

    return 0;
}
