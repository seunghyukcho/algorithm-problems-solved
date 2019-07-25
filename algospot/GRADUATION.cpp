#include<iostream>
#include<algorithm>

using namespace std;

int c, k, l, m, n;

int classes[15];
int cache[12][1 << 15];
int pre[15];

int bitCount(int num){
    int ret = 0;
    for(; num > 0; num /= 2)
        ret += num % 2;

    return ret;
}

int graduate(int semester, int taken){
    if(bitCount(taken) >= k)
        return 0;
    if(semester == m)
        return 1e9;

    int ret = cache[semester][taken];

    if(ret != -1) return ret;
    ret = 1e9;

    int canTake = (classes[semester] & ~taken);
    for(int i = 0; i < n; i++){
        if(((1 << i) & canTake) && (taken & pre[i]) != pre[i])
            canTake &= ~(1 << i);
    }

    for(int i = canTake; i > 0; i = ((i - 1) & canTake)){
        if(bitCount(i) > l)
            continue;
        ret = min(ret, graduate(semester + 1, taken | i) + 1);
    }

    ret = min(ret, graduate(semester + 1, taken));
    return cache[semester][taken] = ret;
}

int main(){
    for(cin >> c; c > 0; c--){
        cin >> n >> k >> m >> l;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < (1 << (n + 1)); j++)
                cache[i][j] = -1;

        for(int i = 0; i < n; i++){
            int num;

            for(pre[i] = 0, cin >> num; num > 0; num--){
                int bit;
                cin >> bit;

                pre[i] |= (1 << bit);
            }
        }

        for(int i = 0; i < m; i++){
            int num;

            for(classes[i] = 0, cin >> num; num > 0; num--){
                int bit;
                cin >> bit;

                classes[i] |= (1 << bit);
            }
        }

        int ans = graduate(0, 0);
        if(ans == 1e9)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }

    return 0;
}
