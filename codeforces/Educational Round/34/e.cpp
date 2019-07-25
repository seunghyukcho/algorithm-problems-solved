#include<iostream>
#include<string>
using  namespace std;
string arr[6250000];
bool no[6250000];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    string fi;
    cin>>fi;
    int ind=0;
    for(int i=0;i<k-1;i++){
        for(int j=i;j<k;j++){
            string b=fi;
            b[i]=fi[j];
            b[j]=fi[i];
            no[ind]=true;
            arr[ind++]=b;
        }
    }

    for(int i=1;i<n;i++){
        string test;
        cin>>test;
        for(int j=0;j<ind;j++){
            if(no[j]==false)
                continue;
            int sum=0;
            for(int q=0;q<k;q++){
                if(test[q]==arr[j][q])
                    sum++;
            }
            if(sum<k-2)
                no[j]=false;
        }
    }
    bool is_out=false;
    for(int i=0;i<ind;i++){
        if(no[i]){
            cout<<arr[i]<<endl;
            is_out=true;
        }
    }
    if(is_out==false)
        printf("-1\n");
}
