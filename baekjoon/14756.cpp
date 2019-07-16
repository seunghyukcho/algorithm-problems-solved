#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

#define _USE_MATH_DEFINES

using namespace std;

typedef complex<double> base;

int power_of_2_ge_than(int n) {
    int ret = 0;
    while((1 << ret) < n) {
        ret++;
    }

    return (1 << ret);
}

void fft(vector<base> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = (inv ? 1 : -1) * M_PI / i;
        base w = { cos(x), sin(x) };
        for (int j = 0; j < n; j += i << 1) {
            base th(1);
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

vector<int> multiply(vector<int> &A, vector<int> &B) {
    vector<base> a(A.begin(), A.end());
    vector<base> b(B.begin(), B.end());
    int n = power_of_2_ge_than(max(a.size(), b.size())) * 2;

    a.resize(n);	b.resize(n);
    fft(a, false);	fft(b, false);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];
    fft(a, true);

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = (int)round(a[i].real());
    return ret;
}

vector<vector<int> > grid(102), tele(102);
vector<int> result2(10002);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, w, ans = 0;
    cin >> n >> l >> m >> w;
    for(int i = 0; i < m; i++)
    {
        grid[i].resize(n);
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    for(int i = 0; i < m; i++)
    {
        tele[i].resize(l);
        for(int j = 0; j < l; j++) cin >> tele[i][j];
        reverse(tele[i].begin(), tele[i].end());
    }

    for(int i = 0; i < m; i++)
    {
        auto result = multiply(grid[i], tele[i]);

        for(int j = l - 1; j < n; j++)
            result2[j - l + 1] += result[j];
    }

    for(int i = l - 1; i < n; i++)
        if(result2[i - l + 1] > w) ans++;

    cout << ans << '\n';
}