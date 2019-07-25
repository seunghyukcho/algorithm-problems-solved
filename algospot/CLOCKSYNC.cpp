#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > control(10);
int t, clk[16];
int ans;

void clock_control(int n, int k){
    if(k >= ans)
        return;

    if(n == 10){
        for(int i = 0; i < 16; i++)
            if(clk[i] != 3)
                return;

        ans = min(ans, k);
        return;
    }

    int rotate = 0;
    for(int i = 0; i < 4; i++){
        clock_control(n + 1, k + rotate);

        for(auto here : control[n])
            clk[here] = (clk[here] + 1) % 4;

        rotate++;
    }
}

int main(){
    control[0] = {0, 1, 2};
    control[1] = {3, 7, 9, 11};
    control[2] = {4, 10, 14, 15};
    control[3] = {0, 4, 5, 6, 7};
    control[4] = {6, 7, 8, 10, 12};
    control[5] = {0, 2, 14, 15};
    control[6] = {3, 14, 15};
    control[7] = {4, 5, 7, 14, 15};
    control[8] = {1, 2, 3, 4, 5};
    control[9] = {3, 4, 5, 9, 13};

    for(cin >> t; t > 0; t--){
        for(int i = 0; i < 16; i++){
            cin >> clk[i];
            clk[i] = (clk[i] / 3) - 1;
        }

        ans = 1e9;
        clock_control(0, 0);

        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }

    return 0;
}
