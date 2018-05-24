#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long LIS[1002][2], LDS[1002][2], num[1002];
long long mod = 20170429;

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> num[i];
            LIS[i][0] = LIS[i][1] = 0;
            LDS[i][0] = LDS[i][1] = 0;
        }
        LIS[0][0] = LIS[0][1] = 1;
        LDS[n - 1][0] = LDS[n - 1][1] = 1;

        for(int i = 1; i < n; i++){
            LIS[i][1] = 1;
            for(int j = 0; j < i; j++){
                if(num[i] > num[j]){
                    if(LIS[i][0] < LIS[j][0]){
                        LIS[i][0] = LIS[j][0];
                        LIS[i][1] = LIS[j][1];
                    }
                    else if(LIS[i][0] == LIS[j][0])
                        LIS[i][1] += LIS[j][1];
                }
            }
            LIS[i][0]++;
        }

        for(int i = n - 2; i >= 0; i--){
            LDS[i][1] = 1;
            for(int j = i + 1; j < n; j++){
                if(num[i] > num[j]){
                    if(LDS[i][0] < LDS[j][0]){
                        LDS[i][0] = LDS[j][0];
                        LDS[i][1] = LDS[j][1];
                    }
                    else if(LDS[i][0] == LDS[j][0])
                        LDS[i][1] += LDS[j][1];
                }
            }
            LDS[i][0]++;
        }

        long long mx[2] = {0, 0};
        for(int i = 0; i < n; i++){
            if(mx[0] < LIS[i][0] + LDS[i][0] - 1){
                mx[0] = LIS[i][0] + LDS[i][0] - 1;
                mx[1] = ((LIS[i][1] % mod) * (LDS[i][1] % mod)) % mod;
            }
            else if(mx[0] == LIS[i][0] + LDS[i][0] - 1){
                mx[1] += ((LIS[i][1] % mod) * (LDS[i][1] % mod)) % mod;
                mx[1] %= mod;
            }
        }

        cout << mx[1] << '\n';
    }

    return 0;
}
