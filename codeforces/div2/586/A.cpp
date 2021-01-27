#include <iostream>
#include <string>
#include <map>

using namespace std;

static int n;
static string s;
static map<char, int> cnt;

int main()
{
    cin >> n >> s;
    for(char ch : s) cnt[ch]++;
    while(cnt['o'] > 0 && cnt['n'] > 0 && cnt['e'] > 0)
    {
        cout << 1 << ' ';
        cnt['o']--, cnt['n']--, cnt['e']--;
    }

    while(cnt['z'] > 0 && cnt['e'] > 0 && cnt['r'] > 0 && cnt['o'] > 0)
    {
        cout << 0 << ' ';
        cnt['z']--, cnt['e']--, cnt['r']--, cnt['o']--;
    }

    cout << '\n';
    
}