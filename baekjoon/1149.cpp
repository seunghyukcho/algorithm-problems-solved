#include<iostream>
#include<algorithm>

using namespace std;

int D[1002][3];
int n, cost[1002][3];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

        D[i][0] = min(D[i - 1][1], D[i - 1][2]) + cost[i][0];
        D[i][1] = min(D[i - 1][0], D[i - 1][2]) + cost[i][1];
        D[i][2] = min(D[i - 1][0], D[i - 1][1]) + cost[i][2];
    }

    cout << min(D[n][0], min(D[n][1], D[n][2])) << '\n';

    return 0;
}
