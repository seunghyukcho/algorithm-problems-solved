#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n;

int main(){
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        vector<int> even, odd;
        int ans = -1;

        cin >> n;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;

            if(i % 2)
                odd.push_back(num);
            else
                even.push_back(num);
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        for(int i = 0; i < even.size() + odd.size() - 1; i++){
            int here1, here2;
            if(i % 2){
                here1 = odd[i / 2];
                here2 = even[(i + 1) / 2];
            }
            else{
                here1 = even[i / 2];
                here2 = odd[(i + 1) / 2];
            }

            if(here1 > here2){
                ans = i;
                break;
            }
        }

        printf("Case #%d: ", cs);
        if(ans == -1)
            printf("OK\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
