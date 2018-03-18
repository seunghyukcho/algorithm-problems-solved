#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long n;
    int b;
    vector<int> ans;

    cin >> n >> b;
    while(n > 0){
        ans.push_back(n % b);
        n /= b;
    }
    
    reverse(ans.begin(), ans.end());
    for(int i : ans){
        if(i < 10)
            cout << i;
        else
            printf("%c", 'A' + i - 10);
    }

    cout << '\n';

    return 0;
}
    
