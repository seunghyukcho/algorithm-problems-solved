#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Trie{
public:
    Trie* go[27];
    Trie* fail;

    bool out;

    Trie(){
        for(int i = 0; i < 26; i++)
            go[i] = NULL;
        out = false;
    }

    void insert(string &s, int here){
        if(s.size() == here)
            out = true;
        else{
            if(!go[s[here] - 'a']){
                go[s[here] - 'a'] = new Trie;
            }

            go[s[here] - 'a']->insert(s, here + 1);
        }
    }
};

bool isexist(string &s, Trie* start){
    Trie* here = start;

    for(int i = 0; i < s.size(); i++){
        int pos = s[i] - 'a';

        while(here != start && !here->go[pos])
            here = here->fail;

        if(here->go[pos])
            here = here->go[pos];
        if(here->out)
            return true;
    }

    return false;
}

void bfs(Trie* root){
    queue<Trie*> q;

    q.push(root);
    while(!q.empty()){
        Trie* here = q.front();
        q.pop();

        for(int i = 0; i < 'z' - 'a' + 1; i++){
            Trie* next = here->go[i];

            if(!next)
                continue;
            if(here == root)
                next->fail = root;
            else{
                Trie* failure = here->fail;
                while(failure != root && !failure->go[i])
                    failure = failure->fail;

                if(failure->go[i])
                    failure = failure->go[i];
                next->fail = failure;
            }

            if(next->fail->out)
                next->out = true;
            q.push(next);
        }
    }
}

int n, q;

int main(){
    Trie* root = new Trie;

    cin >> n;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;

        root->insert(input, 0);
    }
    root->fail = root;
    bfs(root);

    cin >> q;
    for(int i = 0; i < q; i++){
        string input;
        cin >> input;

        cout << (isexist(input, root) ? "YES" : "NO") << '\n';
    }

    return 0;
}
