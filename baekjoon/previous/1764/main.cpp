#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    map<string, int> d;
    int n, m;
    int ans = 0;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        d[s] = 1;
    }

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(d.count(s)){
            ans++;
            d[s]++;
        }
    }
    
    cout << ans << '\n';
    for(auto i : d){
        if(i.second >= 2)cout << i.first << '\n';
    }

    return 0;
}
