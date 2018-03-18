#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b){
    if(b % a == 0)
        return a;
    else return gcd(b % a, a);
}

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int num;
        vector<int> v;
        
        cin >> num;
        for(int i = 0; i < num; i++){
            int n;
            cin >> n; 
            v.push_back(n);
        }

        long long ans = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++)
                ans += gcd(v[i], v[j]);
        }

        cout << ans << '\n';
    }

    return 0;
}
