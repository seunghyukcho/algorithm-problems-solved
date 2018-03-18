#include<iostream>

using namespace std;

int main(){
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++){    
        cin >> num;
        int flag = 0;
        while(num > 0){
            if(num % 2)cout << flag << ' ';
            num /= 2;
            flag++;
        }
        cout << '\n';
    }

    return 0;
}
