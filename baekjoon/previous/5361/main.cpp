#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    vector<float> price(5);
    price[0] = 350.34;
    price[1] = 230.90;
    price[2] = 190.55;
    price[3] = 125.30;
    price[4] = 180.90;

    cin >> t;
    for(int i = 0; i < t; i++){
        float ans = 0;
        for(int j = 0; j < 5; j++){
            int num;
            cin >> num;
            ans += price[j] * num;
        }
        printf("$%.2f\n", ans);
    }

    return 0;
}
