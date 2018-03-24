#include<iostream>

using namespace std;

int r, c;
char map[502][502];

int main(){
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    bool ans = true;

    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> map[i][j];

    for(int i = 0; i < r && ans; i++)
        for(int j = 0; j < c && ans; j++){
            if(map[i][j] == 'S'){
                for(int k = 0; k < 4; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];

                    if(x < 0 || y < 0 || x >= r || y >= c)
                        continue;

                    if(map[x][y] == 'W'){
                        ans = false;
                        break;
                    }

                    if(map[x][y] != 'S')
                        map[x][y] = 'D';
                }
            }
        }

    if(ans){
        printf("Yes\n");
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++)
                printf("%c", map[i][j]);
            printf("\n");
        }
    }
    else
        printf("No\n");

    return 0;
}

