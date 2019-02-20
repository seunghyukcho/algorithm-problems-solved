#include<iostream>
#include<algorithm>
#include<complex>
#include<vector>
#include<string>

using namespace std;

typedef complex<double> base;

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

int n, l, m;
long long w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> m >> w;
    vector<vector<long long> > sky(m, vector<long long>(n)), tel(m, vector<long long>(l));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> sky[i][j];

        reverse(sky[i].begin(), sky[i].end());
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < l; j++)
            cin >> tel[i][j];

    vector<long long> result = multiply(tel[0], sky[0]);
    for(int i = 1; i < m; i++) {
        vector<long long> r = multiply(tel[i], sky[i]);
        for(int j = 0; j < result.size(); j++)
            result[j] += r[j];
    }

    int ans = 0;
    for(int i = l - 1; i < n; i++)
        ans += result[i] > w ? 1 : 0;

    cout << ans << '\n';
    return 0;
}
