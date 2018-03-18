#include<iostream>

using namespace std;

int D[1002];
int val[1002];
int ans;

int dy(int n){
    if(D[n])
        return D[n];

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(val[i] > val[n])
            ret = max(ret, dy(i));
    }

    ret += 1;
    ans = max(ans, ret);
    
    return D[n] = ret;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> val[i];
        dy(i);
    }

    cout << ans << '\n';

    return 0;
}

