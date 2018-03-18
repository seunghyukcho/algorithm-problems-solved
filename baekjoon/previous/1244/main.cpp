#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n+1);
    for(int i = 1; i <= n; i++)cin >> num[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int gender, pick;
        cin >> gender >> pick;
        if(gender == 1){
            int k = pick;
            while(k <= n){
                num[k] ^= 1;
                k += pick;
            }
        }
        else{
            num[pick] ^= 1;
            int left = pick - 1;
            int right = pick + 1;
            while(left > 0 && right <= n && num[left] == num[right]){
                num[left--] ^= 1;
                num[right++] ^= 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << num[i] << ' ';
        if(i % 20 == 0)cout << '\n';
    }
    cout << '\n';

    return 0;
}

