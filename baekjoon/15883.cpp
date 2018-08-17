#include<iostream>
#include<cmath>

using namespace std;

bool check[16];
int value[7], value2[3];

void dfs(int depth) {
    if(depth == 6) {
        //for(int i = 0; i < 16; i++) cout << (check[i] ? 1 : 0) << ' ';
        //cout << '\n';
        int num1 = pow(16, 3) * value[0] + pow(16, 2) * value[1] + pow(16, 1) * value[2] + value[3];
        int num2 = pow(16, 3) * value[4] + pow(16, 2) * value[1] + pow(16, 1) * value[0] + value[5];
        int num3 = num1 + num2;
        int realnum3 = num3;

        for(int i = 0; i < 3; i++, num3 /= 16) {
            if(check[num3 % 16]) {
                for(int j = 0; j < i; j++) check[value2[j]] = false;
                return;
            }
            check[num3 % 16] = true;
            value2[i] = num3 % 16;
        }

        for(int i = 0; i < 3; i++) {
            check[value2[i]] = false;
        }

        if(num3 % 16 != value[3]) return;
        if((num3 / 16) % 16 != value[2]) return;

        printf("%x + %x = %x\n", num1, num2, realnum3);
    }
    else if(depth == 0 || depth == 2 || depth == 4) {
        for(int i = 1; i < 16; i++) {
            if(!check[i]) {
                check[i] = true;
                value[depth] = i;
                dfs(depth + 1);
                check[i] = false;
            }
        }
    }
    else {
        for(int i = 0; i < 16; i++) {
            if(!check[i]) {
                check[i] = true;
                value[depth] = i;
                dfs(depth + 1);
                check[i] = false;
            }
        }
    }
}

int main(){
    dfs(0);

    return 0;
}
