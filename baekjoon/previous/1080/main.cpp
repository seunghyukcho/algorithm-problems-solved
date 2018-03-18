#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat1(n, vector<int>(m));
    vector<vector<int> > mat2(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%1d", &mat1[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)scanf("%1d", &mat2[i][j]);
    }

    int ans = 0;
    for(int i = 0; i <= n - 3; i++){
        for(int j = 0; j <= m - 3; j++){
            if(mat1[i][j] != mat2[i][j]){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        mat1[i + k][j + l] = !mat1[i + k][j + l];;
                    }
                }
                ans++;
            }
        }
    }
    bool check = true;
    for(int i = 0; i < n && check; i++){
        for(int j = 0; j < m; j++){
            if(mat1[i][j] != mat2[i][j]){
                check = false;
                break;
            }
        }
    }

    if(check)cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}
