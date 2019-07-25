#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int T, cache[102][102];
string s, t, p;

bool isMatch(int idx1, int idx2)
{
    int& ret = cache[idx1][idx2];
    if(ret != 0) return (ret == 1 ? true : false);

    ret = -1;
    if(s[idx1] != t[idx2]) ret = -1;
    else if(idx1 == s.size() - 1) ret = 1;
    else 
    {
        for(idx2 += 1; idx2 < t.size(); idx2++)
            if(isMatch(idx1 + 1, idx2)) 
            {
                ret = 1;
                break;
            }
    }
    

    return ret == 1;
}

int main()
{
    for(cin >> T; T > 0; T--)
    {
        vector<int> cnt1(30, 0), cnt2(30, 0);
        cin >> s >> t >> p;

        for(int i = 0; i < s.size(); i++)
            for(int j = 0; j < t.size(); j++) cache[i][j] = 0;

        bool flag = false;
        for(int i = 0; !flag && i < t.size(); i++)
            if(isMatch(0, i)) flag = true;
        
        if(!flag) {
            cout << "NO\n";
            continue;
        }

        for(char ch : t) cnt1[ch - 'a']++;
        for(char ch : s) cnt1[ch - 'a']--;
        for(char ch : p) cnt2[ch - 'a']++;

        flag = true;
        for(int i = 0; flag && i <= 'z' - 'a'; i++)
            if(cnt1[i] > cnt2[i]) flag = false;

        cout << (flag ? "YES" : "NO") << '\n';
    }
}