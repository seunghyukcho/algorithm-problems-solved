#include<iostream>
#include<algorithm>

using namespace std;

struct L{
    int m, e;
};

int n, t;
L box[100002];
bool comp(L l1, L l2){
    return l1.e > l2.e;
}

int main(){
    for(cin >> t; t > 0; t--){
        int ans = 0;

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> box[i].m;
        for(int i = 0; i < n; i++)
            cin >> box[i].e;

        sort(box, box + n, comp);

        int eattime = 0;

        for(int i = 0; i < n; i++){
            eattime += box[i].m;
            ans = max(ans, eattime + box[i].e);
        }

        cout << ans << '\n';
    }

    return 0;
}
