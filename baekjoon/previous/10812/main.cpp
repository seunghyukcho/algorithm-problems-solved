#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)v[i] = i+1;

    for(int a = 0; a < m; a++){
        int i, j, k;
        cin >> i >> j >> k;
        auto it = v.begin();
        rotate(it + i - 1, it + k - 1, it + j);
    }

    for(int i : v)cout << i << ' ';
    cout << '\n';

    return 0;
}


        
