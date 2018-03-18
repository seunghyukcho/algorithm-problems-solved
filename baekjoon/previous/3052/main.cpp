#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    int num = 42;

    for(int i = 0; i < 10; i++){
        int n;
        bool check = true;

        cin >> n;

        for(auto i : v){
            if(i % num == n % num){
                check = false;
                break;
            }
        }

        if(check)
            v.push_back(n);
    }

    cout << v.size() << '\n';

    return 0;
}
