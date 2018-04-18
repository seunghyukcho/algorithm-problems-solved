#include<iostream>
#include<algorithm>

using namespace std;

int h, w, x, y;
int map[1002][1002];
int ans[1002][1002];

int main(){
    cin >> h >> w >> x >> y;
    for(int i = 0; i < h + x; i++)
        for(int j = 0; j < w + y; j++)
            cin >> map[i][j];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans[i][j] = min(map[i][j], map[i + x][j + y]);
            cout << ans[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
