#include<iostream>

using namespace std;

int main(){
    long long num;
    long long max, min;
    cin >> num;
    long long check;
    long long nnum = num + (num & (~num + 1));;
    if(nnum == (num + 1))min = 0;
    else{
        check = 2;
        while(true){
            if((num & check) != 0){
                if(!(num & (check >> 1))){
                    min = num - check + (check >> 1);
                    break;
                }
            }
            check <<= 1;
        }
    }

    check = 1;
    while(true){
        if((num & check) != 0){
            if(!(num & (check << 1))){
                max = num + check;
                break;
            }
        }
        check <<= 1;
    }

    cout << min << ' ' << max << '\n';

    return 0;
}
