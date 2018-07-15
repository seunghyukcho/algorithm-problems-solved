#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = inv ? M_PI / i : -M_PI / i;
        base w = {cos(x), sin(x)};
        for (int j = 0; j < n; j += i << 1) {
            base th = {1, 0};
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

void multiply(vector<base> &a, vector<base> &b) {
    int n = (int) max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    fft(a, true);
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    vector<int> A, B;

    string a, b;
    cin >> a >> b;
    for(auto ch : a) A.push_back(ch - '0');
    for(auto ch : b) B.push_back(ch - '0');

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<int> ret = multiply(A, B);

    int i = 0;
    while (i < ret.size()) {
        if (ret[i] >= 10) {
            if (i == ret.size() - 1)
                ret.push_back(ret[i] / 10);
            else
                ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }
        ++i;
    }

    reverse(ret.begin(), ret.end());

    bool start = false;
    for (auto elem : ret) {
        if (elem)start = true;
        if (start)cout << elem;
    }
    if (!start)cout << '0';

    return 0;
}
