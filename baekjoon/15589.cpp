#include<iostream>
#include<algorithm>

using namespace std;

int top, ans, N, mn = 1e9;

struct LG {
    int start, end, cover, idx;
} cow[100002];

LG st[100002];

bool comp(LG l1, LG l2) { return l1.end < l2.end; }

int main(){
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> cow[i].start >> cow[i].end;
        cow[i].cover = cow[i].end - cow[i].start;
    }
    sort(cow, cow + N, comp);
    for(int i = 0; i < N; i++) cow[i].idx = i;

    for(int i = 0; i < N; i++) {
        while(top && st[top - 1].start >= cow[i].start) {
            if(top == 1 || st[top - 2].end < st[top - 1].start) ans -= st[top - 1].cover;
            else ans -= st[top - 1].end - st[top - 2].end;

            cow[st[top - 1].idx].cover = 0;
            mn = 0;
            top--;
        }

        if(!top) {
            st[top++] = cow[i];
            ans += cow[i].cover;
            mn = min(mn, cow[i].cover);
        } else {
            if(st[top - 1].end > cow[i].start) {
                int diff = st[top - 1].end - cow[i].start;

                ans = ans - diff + cow[i].cover;

                cow[st[top - 1].idx].cover = max(0, cow[st[top - 1].idx].cover - diff);
                cow[i].cover -= diff;

                mn = min(mn, min(cow[st[top - 1].idx].cover, cow[i].cover));
            } else {
                mn = min(mn, cow[i].cover);
                ans += cow[i].cover;
            }
            st[top++] = cow[i];
        }
    }

    cout << ans - mn << '\n';

    return 0;
}
