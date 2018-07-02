#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    string input;
    int A = 0, m, x;

    for(cin >> m; m > 0; m--){
        cin >> input;

        if(input == "add"){
            cin >> x;
            A |= (1 << x);
        }
        else if(input == "remove"){
            cin >> x;
            A &= ~(1 << x);
        }
        else if(input == "check"){
            cin >> x;
            cout <<  (A & (1 << x) ? 1 : 0) << '\n';
        }
        else if(input == "toggle"){
            cin >> x;
            A ^= (1 << x);
        }
        else if(input == "all") A = (1 << 21) - 1;
        else A = 0;
    }

}
