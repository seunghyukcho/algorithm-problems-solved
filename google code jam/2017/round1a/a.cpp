#include<iostream>

using namespace std;

int t, r, c;
char cake[30][30];
char answer[30][30];

void rect_cake(int x, int y, int n1, int n2){
    if(n1 == 1 && n2 == 1)
        answer[x][y] = cake[x][y];
    else if(n1 == 1 && n2 > 1){
        rect_cake(x, y, n1, n2 / 2);
        rect_cake(x, y + n2 / 2, n1, n2 / 2 + (n2 % 2));

        if(answer[x][y] == '?' && answer[x][y + n2 / 2] != '?')
            for(int i = 0; i < n2 / 2; i++)
                answer[x][y + i] = answer[x][y + n2 / 2];
        else if(answer[x][y] != '?' && answer[x][y + n2 / 2] == '?')
            for(int i = 0; i < n2 / 2 + (n2 % 2); i++)
                answer[x][y + n2 / 2 + i] = answer[x][y + n2 / 2 - 1];
    }
    else{
        rect_cake(x, y, n1 / 2, n2);
        rect_cake(x + n1 / 2, y, n1 / 2 + (n1 % 2), n2);

        if(answer[x][y] == '?' && answer[x + n1 / 2][y] != '?')
            for(int i = 0; i < n2; i++)
                for(int j = 0; j < n1 / 2; j++)
                    answer[x + j][y + i] = answer[x + n1 / 2][y + i];
        else if(answer[x][y] != '?' && answer[x + n1 / 2][y] == '?')
            for(int i = 0; i < n2; i++)
                for(int j = 0; j < n1 / 2 + (n1 % 2); j++)
                    answer[x + n1 / 2 + j][y + i] = answer[x + n1 / 2 - 1][y + i];
    }
}

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                cin >> cake[i][j];
                answer[i][j] = '?';
            }

        rect_cake(0, 0, r, c);
        
        cout << "Case #" << cs << ":\n";
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++)
                cout << answer[i][j];
            cout << '\n';
        }
    }

    return 0;
}
