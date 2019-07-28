#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll cache[200002];
string s;
int N;

struct Node
{
    int cnt;
    Node* next[30];

    Node()
    {
        cnt = 0;
        for(int i = 0; i <= 'z' - 'a'; i++) next[i] = NULL;
    }
};

Node* root[30];

ll dp(int idx)
{
    ll& ret = cache[idx];
    if(ret != -1) return ret;

    ret = 0;
    queue<pair<Node*, int> > q;
    q.push({root[s[idx] - 'a'], 1});

    while(!q.empty())
    {
        auto here = q.front(); q.pop();

        if(here.first == NULL) continue;
        ret = (ret + here.first->cnt * (dp(idx + here.second) % MOD)) % MOD;
        if(idx + here.second < s.size()) q.push({here.first->next[s[idx + here.second] - 'a'], here.second + 1});
    }

    return ret;
}

void insert(Node* here, string& t, int idx = 0)
{
    here->cnt++;
    if(idx + 1 == t.size()) return;

    if(here->next[t[idx + 1] - 'a'] == NULL) here->next[t[idx + 1] - 'a'] = new Node();
    insert(here->next[t[idx + 1] - 'a'], t, idx + 1);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        char letter = word[0];
        if(root[letter - 'a'] == NULL) root[letter - 'a'] = new Node();
        insert(root[letter - 'a'], word);
    }

    cin >> s;
    for(int i = 0; i < s.size(); i++) cache[i] = -1;
    cache[s.size()] = 1;

    cout << dp(0) << '\n';
}