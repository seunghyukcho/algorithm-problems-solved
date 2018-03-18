#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    int n;

    for(cin >> n; n > 0; n--){
        int proc;
        cin >> proc;

        if(!proc){
            if(pq.empty())
                printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
            pq.push(proc);
    }

    return 0;
}
