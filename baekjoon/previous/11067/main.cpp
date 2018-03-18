#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    for(cin >> t; t > 0; t--){
        int n;
        cin >> n;

        vector<pair<int, int> > cafe(n);
        
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            cafe[i] = {x, y};
        }
        sort(cafe.begin(), cafe.end());

        for(int i = 1; i < n; i++){
            int j = i;
            while(cafe[j].first != cafe[i - 1].first && cafe[j].second != cafe[i - 1].second)
            {
                j++;
                if(j == n)
                    break;
            }
            if(j != n)
                reverse(cafe.begin() + i, cafe.begin() + j + 1);
            i = j;
        }
        
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            int ans;
            cin >> ans;
            cout << cafe[ans - 1].first << ' ' << cafe[ans - 1].second << '\n';
        }

    }
    return 0;
}
