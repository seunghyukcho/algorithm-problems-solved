#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> cnt(102);
    int sum = 0;
    int mode, c = 0;
    for(int i = 0; i < 10; i++){
        int num;
        cin >> num;
        sum += num;
        cnt[num/10]++;
        if(cnt[num/10] > c){
            mode = num;
            c = cnt[num/10];
        }
    }

    cout << sum/10 << '\n' << mode << '\n';

    return 0;
}

