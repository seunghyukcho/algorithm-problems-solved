#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, int> card;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        card[num]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int num;
        scanf("%d", &num);
        cout << card[num] << ' ';
    }
    cout << '\n';

    return 0;
}
