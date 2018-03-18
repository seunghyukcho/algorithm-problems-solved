#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> ans;

    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];

    int f = 0, l = 0;
    while(f < n && l < m){
        while(f < n && a[f] <= b[l])ans.push_back(a[f++]);
        while(l < m && f < n && b[l] < a[f])ans.push_back(b[l++]);
    }
    if(l < m){
        while(l < m)ans.push_back(b[l++]);
    }
    else if(f < n){
        while(f < n)ans.push_back(a[f++]);
    }

    for(auto i : ans)cout << i << ' ';
    cout << '\n';

    return 0;
}
