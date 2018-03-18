#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long ans = 0;
    int n, i;
    cin >> n;
    vector<long long> v(n);
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    

    for(i = 0; i < n - 1; i++){
        if(v[i] < 0){
            if(v[i + 1] > 0)ans += v[i];
            else{
                ans += v[i] * v[i + 1];
                i++;
            }
        }
        else if(v[i] > 0){
            if(v[i] == 1)ans += v[i];
            else{
                if((n - 1 - i + 1) % 2)ans += v[i];
                else{
                    ans += v[i] * v[i + 1];
                    i++;
                }
            }
        }
    }

    if(i == n - 1)ans += v[n - 1];

    cout << ans << '\n';

    return 0;
}
