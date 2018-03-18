#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<bool> check(1002, true);
    vector<int> prime;
    for(int i = 2; i < 1000; i++){
        if(check[i]){
            prime.push_back(i);
            for(int j = i; j < 1000; j += i)check[j] = false;
        }
    }
    int t;
    cin >> t;
    for(; t > 0; t--){
        int num, ans[3] = {0, 0, 0};
        cin >> num;
        int f, m, l;
        for(f = 0; f < prime.size() - 2; f++){
            m = f;
            l = prime.size() - 1;
            while(m <= l){
                if(prime[f] + prime[m] + prime[l] > num)l--;
                else if(prime[f] + prime[m] + prime[l] < num)m++;
                else break;
            }
            if(m > l)continue;
            else if(prime[f] + prime[m] + prime[l] == num){
                ans[0] = prime[f];
                ans[1] = prime[m];
                ans[2] = prime[l];
                break;
            }
        }
        if(!ans[0])cout << 0 << '\n';
        else cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

    }

    return 0;
}
