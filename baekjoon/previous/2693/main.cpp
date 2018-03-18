#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<int> v(10);
        for(int j = 0; j < 10; j++)cin >> v[j];
        sort(v.begin(), v.end());
        cout << v[7] << '\n';

    }

    return 0;
}
