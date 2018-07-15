#include<iostream>

using namespace std;

int n, a, b, point;
int x[1002][1002];


int main(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> x[i][j];

    for(int i = 1; i <= n; i++) {
        if(x[a][i] > x[a][b] || x[i][b] > x[a][b]) {
            cout << "ANGRY\n";
            return 0;
        }
    }

    cout << "HAPPY\n";
    return 0;
}
