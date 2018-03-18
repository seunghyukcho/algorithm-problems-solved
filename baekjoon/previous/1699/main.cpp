#include<iostream>
#include<vector>

using namespace std;

int D[100002];
vector<int> num;

int dy(int n){
    if(n < 0)
        return 1e9;
    else if(n == 0)
        return 0;
    
    if(D[n])
        return D[n];

    int ret = 1e9;
    for(int i : num)
        ret = min(ret, dy(n - i));

    ret += 1;
    return D[n] = ret;
}

int main(){
    int n;
    cin >> n;

    int val = 1;
    while(val * val <= n){
        num.push_back(val * val);
        val++;
    }

    cout << dy(n) << '\n';
    
    return 0;
}
