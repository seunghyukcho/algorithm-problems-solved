#include<iostream>
#include<vector>

using namespace std;

vector<bool> input(int& n, int& m);
int D(int n, int m, vector<bool> v, vector<vector<int> >& dy);
int min(int a, int b);

int main(){
    int n, m;
    vector<bool> v = input(n, m);
    vector<vector<int> > dy(n + 1, vector<int>(n + 1, -1));
    int ans = D(n, 0, v, dy);
    for(int i = 1; i <= n; i++)ans = min(D(n, i, v, dy), ans);

    cout << ans << '\n';

    return 0;
}

vector<bool> input(int& n, int& m){
    cin >> n >> m;
    vector<bool> v(n + 1, false);
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        v[num] = true;
    }

    return v;
}

int D(int n, int m, vector<bool> v, vector<vector<int> >& dy){
    if(n < 0 || m < 0)return 1e9;
    if(n == 0 && m == 0)return 0;
    else if(n == 0 && m != 0)return 1e9;
    if(dy[n][m] != -1)return dy[n][m];

    dy[n][m] = D(n - 1, m, v, dy) + 10000;
    dy[n][m] = min(dy[n][m], D(n - 3, m - 1, v, dy)) + 25000;
    dy[n][m] = min(dy[n][m], D(n - 5, m - 2, v, dy)) + 37000;
    dy[n][m] = min(dy[n][m], D(n - 1, m + 3, v, dy));
    if(v[n - 1])dy[n][m] = min(dy[n][m], D(n - 1, m, v, dy));

    return dy[n][m];
}
