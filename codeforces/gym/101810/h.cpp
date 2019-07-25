#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int su;
        scanf("%d",&su);
        vector<int> a1,a2;
        for(int i=0;i<su;i++){
            int tmp;
            scanf("%d",&tmp);
            a1.push_back(tmp);
        }
        for(int i=0;i<su;i++){
            int tmp;
            scanf("%d",&tmp);
            a2.push_back(tmp);
        }
        reverse(a2.begin(),a2.end());
        int answer=0;
        for(int i=0;i<su;i++){
            answer=max(answer,a1[i]+a2[i]);
        }
        printf("%d\n",answer);
    }
}
