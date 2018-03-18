#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for(int i = 0; i < n; i++)v[i] = i+1;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        swap(v[a-1], v[b-1]);
    }

    for(int i : v)cout << i << ' ';
    cout << '\n';

    return 0;
}
