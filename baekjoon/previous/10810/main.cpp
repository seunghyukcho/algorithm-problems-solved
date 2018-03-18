#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> ball(n, 0);

    for(int i = 0; i < m; i++){
        int f, l, num;
        cin >> f >> l >> num;
        for(int j = f-1; j < l; j++)ball[j] = num;
    }

    for(int i : ball)cout << i << ' ';

    cout << '\n';

    return 0;
}
