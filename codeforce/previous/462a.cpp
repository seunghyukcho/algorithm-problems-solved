#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<long long> a, b;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        a.push_back(num);
    }

    for(int i = 0; i < m; i++){
        long long num;
        cin >> num;
        b.push_back(num);
    }

    long long mx[3] = {0, 0, 0};
    long long ans = -1e18;
    
    mx[0] = a[0] * b[0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] * b[j] > mx[0]){
                mx[0] = a[i] * b[j];
                mx[1] = i;
                mx[2] = j;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] * b[j] > ans && i != mx[1])
                ans = a[i] * b[j];
        }
    }

    cout << ans << '\n';

    return 0;
}



