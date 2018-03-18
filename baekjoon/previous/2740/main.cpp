#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<vector<int> > mat1(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> mat1[i][j];
    }
    cin >> m >> k;
    vector<vector<int> > mat2(m, vector<int>(k));
    vector<vector<int> > ans(n, vector<int>(k, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++)cin >> mat2[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int l = 0; l < m; l++){
                ans[i][j] += mat1[i][l] * mat2[l][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
