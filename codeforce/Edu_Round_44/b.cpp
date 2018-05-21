#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
int connected[2002];
int lamp[2002][2002];

bool check(){
    for(int i = 0; i < n; i++){
        int lamp_num;
        for(lamp_num = 0; lamp_num < m; lamp_num++){
            if(lamp[i][lamp_num] == 1 && connected[lamp_num] == 1)
                break;
        }

        if(lamp_num == m)
            return true;
    }

    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            lamp[i][j] = input[j] - '0';
            connected[j] += lamp[i][j];
        }
    }

    cout << (check() ? "YES" : "NO") << '\n';

    return 0;
}
