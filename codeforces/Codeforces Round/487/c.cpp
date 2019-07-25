#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> num[4];
int n = 0, m = 0;
int ans[52][52];


int main(){
    for(int i = 0; i < 4; i++){
        int input;
        cin >> input;

        num[i] = {-input, i};
    }

    sort(num, num + 4);

    while(num[1].first < 0){
        for(int i = 0; i < 4 && num[i].first < 0; i++){
            if(n > 0 && ans[n - 1][m] == i)
                continue;

            ans[n][m++] = i;
            num[i].first++;

            if(m == 50){
                n++;
                m = 0;
            }
        }
    }

    while(num[0].first < 0){

    }

    if(n > 0 && m != 0){
        for(int i = m; i < 50; i++)
            ans[n][i] = ans[n - 1][i];
    }


    return 0;
}
