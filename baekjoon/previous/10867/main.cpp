#include<iostream>
#include<set>

using namespace std;

int main(){
    int n;
    set<int> ss;

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        ss.insert(num);
    }

    for(auto  i : ss){
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}

