#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int mid;
    int u=n/2;
    int d;
    if(n%2==0){
        d=n/2+1;
    }
    else{
        d=n/2+2;
    }
    vector<int> up1,down1,up2,down2;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp<=u)
            up1.push_back(i);
        if(tmp>u+n%2)
            up2.push_back(i);
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp>=d)
            down1.push_back(i);
        if(tmp<d-n%2)
            down2.push_back(i);
    }
    long long int sum1=0,sum2=0;
    for(int i=0;i<up1.size();i++){
        sum1 += abs(up1[i]-down1[i]);
    }
    for(int i=0;i<up2.size();i++){
        sum2+=abs(up2[i]-down2[i]);
    }
    cout << min(sum1,sum2) <<endl;
}
