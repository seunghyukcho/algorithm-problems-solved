#include<iostream>
#include<vector>

using namespace std;

int pow(int num, int a){
    int ans = 1;
    for(int i = 0; i < a; i++)ans *= num;
    return ans;
}
int main(){
    vector<int> num(4);
    for(int i = 0; i < 4; i++)cin >> num[i];
    int pos = 0;
    for(int i = 1; i < 4; i++){
        if(num[i] < num[pos])pos = i;
        else if(num[i] == num[pos]){
            int flag = 1;
            while(num[(i+flag)%4] == num[(pos+flag)%4] && flag < 4)flag++;
            if(flag != 4){
                pos =  num[(i+flag)%4] < num[(pos+flag)%4] ? i : pos;
            }
        }
    }
    int a = 0;
    for(int i = 0; i < 4; i++)a += pow(10, 3 - i) * num[(pos+i)%4];
    int ans = 0;
    for(int i = 1; i <= num[pos]; i++){
        for(int j = i; j <= 9; j++){
            for(int k = i; k <= 9; k++){
                for(int l = i; l <= 9; l++){
                    int n = 1000*i + 100*j + 10*k + l;
                    if(i == k){
                        if(j > l)continue;
                    }
                    else if(i == l){
                        if(i != j || i != k)continue;
                    }
                    if(n <= a)ans ++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
