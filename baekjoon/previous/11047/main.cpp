#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> coin;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        coin.push_back(num);
    }
    reverse(coin.begin(), coin.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += k / coin[i];
        k %= coin[i];
    }

    cout << ans << '\n';

    return 0;
}

