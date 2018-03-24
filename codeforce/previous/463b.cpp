#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int F[5000000];
int D[5000000];
vector<vector<int> > ans(10);

long long f(long long num){
    if(F[num])
        return F[num];
    
    long long ret = 1;
    while(num > 0){
        ret *= (num % 10 ? num % 10 : 1);
        num /= 10;
    }

    return F[num] = ret;
}

int g(int num){
    if(D[num])
        return D[num];
    else if(num < 10){
        D[num] = num;
        ans[D[num]].push_back(num);
        return D[num];
    }
    else{
        D[num] = g(f(num));
        ans[D[num]].push_back(num);
        return D[num];
    }
}

int q, l, r, k;

int main(){
    for(int i = 1; i <= 1e6; i++)
        D[i] = 0;
    for(int i = 1; i <= 1e6; i++)
        g(i);
    
    for(cin >> q; q > 0; q--){
        cin >> l >> r >> k;
        int output = 0;
        
        output = (int)(upper_bound(ans[k].begin(), ans[k].end(), r) - lower_bound(ans[k].begin(), ans[k].end(), l));
                 
        cout << output << '\n';
    }

    return 0;
}


