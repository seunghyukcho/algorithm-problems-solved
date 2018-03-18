#include<iostream>
#include<vector>

using namespace std;

void quadtree(int x, int y, int size, vector<vector<int> > &v){
    int num = v[x][y];
    bool check = true;
    for(int i = 0; check && i < size; i++){
        for(int j = 0; check && j < size; j++){
            if(num != v[x + i][y + j])check = false;
        }
    }
    if(check)cout << num;
    else{
        cout << '(';
        quadtree(x, y, size / 2, v);
        quadtree(x, y + size / 2, size / 2, v);
        quadtree(x + size / 2, y, size / 2, v);
        quadtree(x + size / 2, y + size / 2, size / 2, v);
        cout << ')';
    }

    return;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > quad(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)scanf("%1d", &quad[i][j]);
    }

    quadtree(0, 0, n, quad);
    cout << '\n';
    return 0;
}
