#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct Element {
    int num, idx;
} E[100002];

int N;
bool comp(Element e1, Element e2) { return e1.num == e2.num ? e1.idx < e2.idx : e1.num < e2.num; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> E[i].num;
        E[i].idx = i;
    }

    sort(E + 1, E + N + 1, comp);
    int ans = 0;

    for(int i = 1; i <= N; i++)
        if(i < E[i].idx) ans = max(ans, abs(i - E[i].idx));

    cout << ans + 1 << '\n';

    return 0;
}
