#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MAXN 500005

using namespace std;

struct Suffix {
    string s;
    int SA[MAXN][2], N1, N2, N, LCP[MAXN];
    int ord[MAXN][2], nord[MAXN][2], cnt[MAXN], aux[MAXN][2], pnt = 1;

    void suffix_array() {
        for(int i = 0; i < N; i++) {
            SA[i][0] = i, SA[i][1] = (i < N1 ? 0 : 1);
            ord[i][0] = s[i], ord[i][1] = (i < N1 ? 0 : 1);

            aux[i][0] = aux[i][1] = 0;
        }

        for(int p = 1; p < N; p *= 2) {
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < N; i++) cnt[ord[min(i + p, N)][0]]++;
            for(int i = 1; i <= N || i <= 255; i++) cnt[i] += cnt[i - 1];
            for(int i = N - 1; i >= 0; i--) {
                aux[--cnt[ord[min(i + p, N)][0]]][0] = i;
                aux[cnt[ord[min(i + p, N)][0]]][1] = ord[min(i + p, N)][1];
            }

            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < N; i++) cnt[ord[i][0]]++;
            for(int i = 1; i <= N || i <= 255; i++) cnt[i] += cnt[i - 1];
            for(int i = N - 1; i >= 0; i--) {
                SA[--cnt[ord[aux[i][0]][0]]][0] = aux[i][0];
                SA[cnt[ord[aux[i][0]][0]]][1] = ord[aux[i][0]][1];
            }

            if(pnt == N) break;
            pnt = 1;
            nord[SA[0][0]][0] = 1, nord[SA[0][0]][1] = SA[0][1];
            for(int i = 1; i < N; i++) {
                if(ord[SA[i - 1][0]][0] != ord[SA[i][0]][0] || ord[SA[i - 1][0] + p][0] != ord[SA[i][0] + p][0]) pnt++;
                nord[SA[i][0]][0] = pnt, nord[SA[i][0]][1] = SA[i][1];
            }

            for(int i = 0; i < N; i++) ord[i][0] = nord[i][0], ord[i][1] = nord[i][1];
        }
    }

    void lcp(){
		vector<int> rev(N + 1, 0);
        for(int i = 0; i < N; i++) rev[SA[i][0]] = i;

        int h = 0;
		for(int i = 0; i < N; i++){
			if(rev[i]){
				int prv = SA[rev[i] - 1][0];
				while(s[prv + h] == s[i + h]) h++;
				LCP[rev[i]] = h;
			}
			h = max(h - 1, 0);
		}
	}
} S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() < s2.size()) swap(s1, s2);
    S.s = s1 + '0' + s2;
    S.N1 = s1.size(), S.N2 = s2.size(), S.N = S.N1 + S.N2 + 1;
    //cout << S.N1 << ' ' << S.N2 << '\n';
    S.suffix_array();
    S.lcp();

    int ans = 0, idx = 0;
    for(int i = 1; i < S.N; i++) {
        if(S.SA[i][1] != S.SA[i - 1][1]) {
            if(ans < S.LCP[i]) {
                ans = S.LCP[i];
                idx = S.SA[i][0];
            }
        }
    }

    cout << ans << '\n';
    for(int i = idx; i < idx + ans; i++) cout << S.s[i];
    cout << '\n';
    return 0;
}
