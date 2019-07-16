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

void fft(vector<base>& input, vector<base>& output, base w)
{
    int n = input.size();
    output.resize(n);
    
    if(input.size() == 1)
    {
        output[0] = input[0];
        return;
    }

    vector<base> inputEven, inputOdd, outputEven, outputOdd;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0) inputEven.push_back(input[i]);
        else inputOdd.push_back(input[i]);
    }
    
    fft(inputEven, outputEven, w * w);
    fft(inputOdd, outputOdd, w * w);

    base wi = 1;
    for(int i = 0; i < n / 2; i++) {
        output[i] = outputEven[i] + wi * outputOdd[i];
        wi *= w;
    }

    for(int i = 0; i < n / 2; i++) {
        output[n / 2 + i] = outputEven[i] + wi * outputOdd[i];
        wi *= w;
    }
}

void multiply(vector<int>& A, vector<int>& B, vector<int>& C)
{
    vector<base> a, b, c, dfta, dftb, dftc;
    int sz;

    for(int digit : A) a.push_back(digit);
    for(int digit : B) b.push_back(digit);
    sz = 1 << ((int)ceil(log2(max(a.size(), b.size()))) + 1);

    a.resize(sz);
    b.resize(sz);

    base w = exp(base(0, 2 * M_PI / sz));
    fft(a, dfta, w);
    fft(b, dftb, w);

    for(int i = 0; i < dfta.size(); i++) c.push_back(dfta[i] * dftb[i]);
    w = base(1, 0) / w;
    fft(c, dftc, w);

    for(base digit : dftc) C.push_back(round(digit.real() / sz));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    vector<int> num1, num2, ans;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(char ch : a) num1.push_back(ch - '0');
    for(char ch : b) num2.push_back(ch - '0');

    multiply(num1, num2, ans);
    for(int i = 0; i < ans.size() - 1; i++)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }

    int end = ans.size() - 1;
    for(; end > 0 && ans[end] == 0; end--);
    for(; end >= 0; end--) cout << ans[end];
    cout << '\n';
}