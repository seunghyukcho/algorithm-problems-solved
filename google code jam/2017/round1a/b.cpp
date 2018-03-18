#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int t, n, p;
long long ingredient[52];

int main(){
    cin >> t;

    for(int cs = 1; cs <= t; cs++){
        int ans = 0;
        vector<map<int, int> > kit(52);
        
        cout << "Case #" << cs << ": ";

        cin >> n >> p;
        for(int i = 0; i < n; i++)
            cin >> ingredient[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < p; j++){
                int num, h;
                cin >> num;

                for(h = 1; ingredient[i] * h * 0.9 <= num; h++){
                    if(ingredient[i] * h * 1.1 >= num)
                        kit[i][h]++;    
                }
                
            }

        for(auto here : kit[0]){
            int mn = here.second;
            
            for(int i = 1; i < n; i++){
                mn *= kit[i][here.first];
            }

            if(mn > 0)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
