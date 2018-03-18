#include<iostream>
#include<set>

using namespace std;

int main(){
    int n, m;
    set<int> card;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        card.insert(num);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        cout << card.count(num) << ' ';
    }

    cout << '\n';

    return 0;
}
