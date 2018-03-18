#include<iostream>

using namespace std;

int D1[1002];
int D2[1002];
int val[1002];
int N;

int dy1(int n){
    if(D1[n])
        return D1[n];

    int ret = 0;
    for(int i = 0; i < n; i++){
        if(val[i] < val[n])
            ret = max(ret, dy1(i));
    }

    ret += 1;

    return D1[n] = ret;
}

int dy2(int n){
    if(D2[n])
        return D2[n];

    int ret = 0;
    for(int i = n + 1; i < N; i++){
        if(val[n] > val[i])
            ret = max(ret, dy2(i));
    }

    ret += 1;

    return D2[n] = ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> val[i];
        dy1(i);
    }
    for(int i = 0; i < N; i++)
        dy2(i);

    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, D1[i] + D2[i] - 1);

    cout << ans << '\n';

    return 0;
}

    
