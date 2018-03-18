#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int n, m;
        int ans = 0;
        cin >> n >> m;

        vector<int> x(m), y(m);
        vector<int> num(n);

        for(int i = 0; i < m; i++)
            cin >> x[i];
        for(int i = 0; i < m; i++)
            cin >> y[i];
        for(int i = 0; i < n; i++)
            cin >> num[i];

        int i, j;
        for(i = 0; i < n; i++){
            bool check1 = false;
            bool check2 = false;
            for(j = 0; j < m; j++){
                int here = i + j;
                        
                if((!check1 && num[here % n] < x[j]) || (!check2 && num[here % n] > y[j]))
                    break;
                if(num[here % n] > x[j])
                    check1 = true;
                if(num[here % n] < y[j])
                    check2 = true;    
            }
            if(j == m){
                ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}


