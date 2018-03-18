#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector<int> sum;
    sum.push_back(0);
    int flag = 0;
    int number = 1;
    int hap = 0;
    for(int i = 0; i < 1001; i++){
        hap += number;
        flag++;
        if(flag == number){
            flag = 0;
            number++;
        }
        sum.push_back(hap);
    }
    cout << sum[b] - sum[a-1] << '\n';

    return 0;
}
