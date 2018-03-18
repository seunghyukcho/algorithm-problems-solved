#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;

    while(getline(cin, s)){
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        for(char c : s){
            if(c >= 'a' && c <= 'z')lower++;
            else if(c >= 'A' && c <= 'Z')upper++;
            else if(c >= '0' && c <= '9')number++;
            else space++;
        }

        cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
    }

    return 0;

}
