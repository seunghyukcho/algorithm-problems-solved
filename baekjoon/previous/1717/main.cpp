#include<iostream>
#include<vector>

using namespace std;

vector<int> par(1000002);
vector<int> len(1000002, 1);

int search(int s){
    if(par[s] == s)
        return s;
    else
        return par[s] = search(par[s]);
}

int main(){
    int n, m;
     
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++)
        par[i] = i;

    for(; m > 0; m--){
        int proc, a, b;
        cin >> proc >> a >> b;

        if(proc == 0){
            if(a == b)
                continue;
            else if(len[a] == len[b]){
                par[a] = b;
                len[b]++;
            }
            else  if(len[a] < len[b]){
                par[a] = b;
            }
            else{
                par[b] = a;
            }
        }
        else
            printf("%s\n", search(a) == search(b) ? "YES" : "NO");
    }

    return 0;
}
