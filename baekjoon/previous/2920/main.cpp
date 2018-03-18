#include<iostream>

using namespace std;

int main(){
    int flag = 0;
    int num;
    cin >> num;
    for(int i = 0; i < 7; i++){
        int n;
        cin >> n;
        if(num < n){
            if(flag < 0){
                flag = 0;
                break;
            }
            else flag = 1;
        }
        else{
            if(flag > 0){
                flag = 0;
                break;
            }
            else flag = -1;
        }
        num = n;
    }
    if(!flag)cout << "mixed" << '\n';
    else if(flag == 1)cout << "ascending" << '\n';
    else cout << "descending" << '\n';

    return 0;
}
