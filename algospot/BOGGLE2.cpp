#include<iostream>
#include<string>

using namespace std;

int n, t;
char boggle[5][5];
int D[5][5][15];

int dfs(int i, int j, int here, string s){
    if(D[i][j][here] != 0)
        return D[i][j][here];

    int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

    if(here == s.size())
        return D[i][j][here] = 1;


    for(int k = 0; k < 8; k++){
        int nextx = dir[k][0] + i;
        int nexty = dir[k][1] + j;

        if(nextx < 0 || nexty < 0 || nextx >= 5 || nexty >= 5 || boggle[nextx][nexty] != s[here])
            continue;

        if(dfs(nextx, nexty, here + 1, s) == 1)
            return D[i][j][here] = 1;
    }

    return D[i][j][here] = -1;
}

int main(){
    for(cin >> t; t > 0; t--){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> boggle[i][j];


        cin >> n;
        for(int i = 0; i < n; i++){
            for(int x = 0; x < 5; x++)
                for(int y = 0; y < 5; y++)
                    for(int z = 0; z < 15; z++)
                        D[x][y][z] = 0;

            string s;
            cin >> s;

            bool check = true;
            for(int x = 0; check && x < 5; x++)
                for(int y = 0; check && y < 5; y++)
                    if(dfs(x, y, 0, s) == 1)
                        check = false;

            cout << s << ' ';
            if(check)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}
