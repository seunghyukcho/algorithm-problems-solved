#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAXN 500002

using namespace std;

static string s;
static int sa[MAXN], lcp[MAXN], cnt[MAXN], ord[MAXN], nord[MAXN], aux[MAXN], rsa[MAXN];

void suffix_array_init()
{
    int sz = s.size(), len = 1, pcnt = 1;

    for(int i = 0; i < sz; i++) sa[i] = i, ord[i] = s[i] - 'a' + 1;
    while(1)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < sz; i++) cnt[ord[min(i + len, sz)]]++;
        for(int i = 1; i <= sz || i <= 'z'; i++) cnt[i] += cnt[i - 1];
        for(int i = sz - 1; i >= 0; i--) aux[--cnt[ord[min(i + len, sz)]]] = i;

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < sz; i++) cnt[ord[i]]++;
        for(int i = 1; i <= sz || i <= 'z'; i++) cnt[i] += cnt[i - 1];
        for(int i = sz - 1; i >= 0; i--) sa[--cnt[ord[aux[i]]]] = aux[i];

        if(pcnt == sz) break;
        pcnt = 1, nord[sa[0]] = 1;
        
        for(int i = 1; i < sz; i++)
        {
            if(ord[sa[i]] != ord[sa[i - 1]] || ord[sa[i] + len] != ord[sa[i - 1] + len]) pcnt++;
            nord[sa[i]] = pcnt;
        }

        for(int i = 0; i < sz; i++) ord[i] = nord[i];
        len <<= 1;
    }

    for(int i = 0; i < sz; i++) rsa[sa[i]] = i;

    int here = 0;
    for(int i = 0; i < sz; i++)
    {
        if(rsa[i])
        {
            int j = sa[rsa[i] - 1];
            while(i + here < sz && j + here < sz && s[i + here] == s[j + here]) here++;
            lcp[rsa[i]] = here;
        }

        here = max(here - 1, 0);
    }
}

int main()
{
    cin >> s;
    suffix_array_init();

    for(int i = 0; i < s.size(); i++) cout << sa[i] + 1 << ' ';
    cout << "\nx ";
    for(int i = 1; i < s.size(); i++) cout << lcp[i] << ' ';
    cout << '\n';
    return 0;
}