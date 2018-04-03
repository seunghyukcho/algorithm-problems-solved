#include<iostream>
#include<string>

using namespace std;

int n, size, s[10002];

int main(){
    for(cin >> n; n > 0; n--){
        string input;
        cin >> input;

        if(input == "push")
            cin >> s[size++];
        else if(input == "pop"){
            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", s[--size]);
        }
        else if(input == "size")
            printf("%d\n", size);
        else if(input == "empty")
            printf("%d\n", size ? 0 : 1);
        else{
            if(size == 0)
                printf("-1\n");
            else
                printf("%d\n", s[size - 1]);
        }
    }

    return 0;
}
