#include<iostream>
#include<vector>

using namespace std;

int main(){
    char s;
    vector<int> al(30, 0);

    while(scanf("%c", &s) == 1){
        al[s - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", al[i]);
    }

    printf("\n");

    return 0;
}
