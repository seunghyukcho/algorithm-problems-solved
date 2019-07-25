#include<iostream>
#include<vector>

using namespace std;

int sort(vector<int>& v, int size){
    vector<int> num(size + 2, -1);
    for(int i = 0; i <= size; i++)num[v[i]] = i;

    int here = 1;
    int max = 0;
    while(here <= size){
        int check = 1;
        while(here <= size && num[here] < num[here + 1]){
            check++;
            here++;
        }
        max = max > check ? max : check;
        here++;
    }

    return max;
}

int main(){
    int n;
    cin >> n;
    vector<int> car(n + 1);
    for(int i = 0; i < n; i++)cin >> car[i];

    cout << n - sort(car, n) << '\n';

    return 0;
}
