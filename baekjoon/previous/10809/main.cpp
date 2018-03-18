#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> al(30, -1);

    char c;
    int i = 0;
    while(scanf("%c", &c) == 1){
        if(al[c - 'a'] == -1)al[c - 'a'] = i;
        i++;
    }
    
    for(i = 0; i < 26; i++){
        printf("%d ",al[i]);
    }

    return 0;
}
