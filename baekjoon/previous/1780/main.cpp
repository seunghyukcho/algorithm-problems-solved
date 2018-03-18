#include<iostream>
#include<vector>

using namespace std;

int ans[3];
void s(int x, int y, int size, vector<vector<int> > &v){
    int num = v[x][y];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(num != v[x + i][y + j]){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++)s(x + k * size / 3, y + l * size / 3, size / 3, v);
                }
                return;
            }
        }
    }
    ans[num + 1]++;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > paper(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin >> paper[i][j];
    }
    
    s(0, 0, n, paper);

    for(int i = 0; i < 3; i++)cout << ans[i] << '\n';

    return 0;
}

