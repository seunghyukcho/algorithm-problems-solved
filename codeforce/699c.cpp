#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    int n;
    cin >> n;
    vector<int> rest(n + 1);
    int D[102][3];
    D[0][0] = 0;
    D[0][1] = 1e9;
    D[0][2] = 1e9;
    for(int i = 1; i <= n; i++)cin >> rest[i];

    for(int i = 1; i <= n; i++){
        if(!rest[i]){
            D[i][1] = 1e9;
            D[i][2] = 1e9;
            D[i][0] = min(D[i - 1][0], min(D[i - 1][1], D[i - 1][2])) + 1;
        }
        else if(rest[i] == 1){
            D[i][2] = 1e9;
            D[i][0] = min(D[i - 1][0], min(D[i - 1][1], D[i - 1][2])) + 1;
            D[i][1] = min(D[i - 1][0], D[i - 1][2]);
        }
        else if(rest[i] == 2){
            D[i][1] = 1e9;
            D[i][0] = min(D[i - 1][0], min(D[i - 1][1], D[i - 1][2])) + 1;
            D[i][2] = min(D[i - 1][0], D[i - 1][1]);
        }
        else{
            D[i][0] = min(D[i - 1][0], min(D[i - 1][1], D[i - 1][2])) + 1;
            D[i][1] = min(D[i - 1][0], D[i - 1][2]);
            D[i][2] = min(D[i - 1][0], D[i - 1][1]);
        }
    }

    int ans = min(D[n][0], min(D[n][1], D[n][2]));

    cout << ans << '\n';
 
    return 0;
}
 
