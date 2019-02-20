#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> a;
int D[2020];
int twos[2020];
int ones[2020];

int dy(int num){
    if(num == 0)
        return D[num] = 1;
    if(D[num])
        return D[num];
    
    for(int i = 0; i < num; i++){
        if(a[i] <= a[num])
            D[num] = max(D[num], dy(i) + 1);
    }

    return D[num];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.push_back(num);

        if(i == 0){
            if(num == 1)
                ones[i] = 1;
            else
                twos[i] = 1;
        }
        else{
            ones[i] = ones[i - 1] + (num == 1 ? 1 : 0);
            twos[i] = twos[i - 1] + (num == 2 ? 1 : 0);
        }
    }

    int lnd = 0;
    vector<bool> check(n, true);

    for(int i = 0; i < n; i++)
        lnd = max(lnd, dy(i));

    int mx[3] = {lnd, 0, 0};    
    for(int i = 0; i < n; i++){
        if(check[i] && a[i] == 2){
            int j;
            int one_num = 0;
            int two_num = 0;
            for(j = i; j < n && a[j] == 2; j++){
                check[j] = false;
                two_num++;
            }

            for(; j <= n; j++){
                if(j == n || a[j] == 2){
                    mx[0] = max(mx[0], ones[i] + two_num + one_num + twos[n - 1] - twos[j - 1]);
                    if(j == n)
                        break;
                    while(j < n && a[j] == 2)
                        j++;
                    j--;
                }
                else
                    one_num++;
            }
        }
    }

    cout << mx[0] << '\n';

    return 0;
}
