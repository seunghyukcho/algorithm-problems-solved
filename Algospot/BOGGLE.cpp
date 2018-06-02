#include<iostream>
#include<string>

using namespace std;

int n, t;
char boggle[5][5];

bool dfs(int i, int j, int here, string s){
    int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};

    if(here == s.size())
        return true;

    for(int k = 0; k < 8; k++){
        int nextx = dir[k][0] + i;
        int nexty = dir[k][1] + j;

        if(nextx < 0 || nexty < 0 || nextx >= 5 || nexty >= 5 || boggle[nextx][nexty] != s[here])
            continue;

        if(dfs(nextx, nexty, here + 1, s))
            return true;
    }

    return false;
}

int main(){
    for(cin >> t; t > 0; t--){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> boggle[i][j];

        cin >> n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;

            bool check = true;
            for(int x = 0; check && x < 5; x++)
                for(int y = 0; check && y < 5; y++)
                    if(dfs(x, y, 0, s))
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
