#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef long long ll;

long long power_of_2_ge_than(long long n) {
    long long ret = 0;
    while((1 << ret) < n) {
        ret++;
    }

    return (1 << ret);
}

void fft(vector<base> &a, bool inv) {
    long long n = a.size();
    for(long long i = 1, j = 0; i < n; i++) {
        long long bit = n >> 1;
        while(!((j ^= bit) & bit)) bit >>= 1;
        if(i < j) swap(a[i], a[j]);
    }

    for(long long i = 1; i < n; i <<= 1) {
        double x = (inv ? 1 : -1) * M_PI / i;
        base w = { cos(x), sin(x) };

        for(long long j = 0; j < n; j += i << 1) {
            base th(1);
            for(long long k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;

                th *= w;
            }
        }
    }

    if(inv) {
        for(long long i = 0; i < n; i++) a[i] /= n;
    }
}

vector<long long> multiply(vector<long long> &A, vector<long long> &B) {
    vector<base> a(A.begin(), A.end());
    vector<base> b(B.begin(), B.end());

    long long n = power_of_2_ge_than((a.size() < b.size() ? b.size() : a.size())) * 2;

    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);

    for(long long i = 0; i < n; i++) {
        a[i] *= b[i];
    }

    fft(a, true);

    vector<long long> ret(n);
    for(long long i = 0; i < n; i++) {
        ret[i] = (long long)round(a[i].real());
    }

    return ret;
}

int n, m, ans;
string rps, machine;
vector<ll> answer, here1, here2, result;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> rps >> machine;
    here1 = vector<ll>(n + m);
    here2 = vector<ll>(m);

    for(int i = 0; i < n; i++)
        here1[m + n - 1 - i] = (rps[i] == 'S') ? 1 : 0;
    for(int i = 0; i < m; i++)
        here2[i] = (machine[i] == 'R') ? 1 : 0;

    answer = multiply(here1, here2);

    for(int i = 0; i < n; i++)
        here1[m + n - 1 - i] = (rps[i] == 'P') ? 1 : 0;
    for(int i = 0; i < m; i++)
        here2[i] = (machine[i] == 'S') ? 1 : 0;

    result = multiply(here1, here2);
    for(int i = 0; i < result.size(); i++) answer[i] += result[i];

    for(int i = 0; i < n; i++)
        here1[m + n - 1 - i] = (rps[i] == 'R') ? 1 : 0;
    for(int i = 0; i < m; i++)
        here2[i] = (machine[i] == 'P') ? 1 : 0;

    result = multiply(here1, here2);
    for(int i = m - 1; i < n + m; i++) {
        answer[i] += result[i];
        ans = max(ans, (int)answer[i]);
    }

    cout << ans << '\n';
}
