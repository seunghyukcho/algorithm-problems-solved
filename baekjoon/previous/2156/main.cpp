#include<iostream>
#include<vector>

using namespace std;

vector<int> D(10001, -1);
vector<int> juice(10001);

int max(int a, int b){
    return a > b ? a : b;
}

int Dy(int n){
    if(n < 0)return 0;
    if(D[n] != -1)return D[n];
    if(n == 0)return D[n] = juice[n];
    return D[n] = max(juice[n] + max(juice[n - 1] + Dy(n - 3), Dy(n - 2)), Dy(n - 1));
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> juice[i];

    cout << Dy(n - 1) << '\n';
    return 0;
}
