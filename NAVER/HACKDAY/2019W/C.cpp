#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static int cache[1002];

struct Node
{
    int score;
    Node *next[10];
    
    Node()
    {
        score = 0;
        for(int i = 0; i < 10; i++) next[i] = NULL;
    }
} *root;

static int idx(char ch)
{
    switch(ch)
    {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'X':
            return 3;
        case 'Y':
            return 4;
        case 'Z':
            return 5;
        case '^':
            return 6;
        case 'v':
            return 7;
        case '<':
            return 8;
        case '>':
            return 9;
        default:
            return -1;
    }
}

void insert(string str, int score)
{
    Node *here = root;
    for(int i = 0; i < str.size(); i++)
    {
        int invert = idx(str[i]);
        if(here->next[invert] == NULL)
            here->next[invert] = new Node();
        here = here->next[invert];
    }
    
    here->score += score;
}

int dp(int here, string& command)
{
    if(here >= command.size()) return 0;
    int& ret = cache[here];
    if(ret != -1) return ret;
    cout << here << '\n';
    
    ret = dp(here + 1, command) + 1;
    Node *node = root;
    for(int i = 0; here + i < command.size(); i++)
    {
        int invert = idx(command[here + i]);
        if(node->next[invert] == NULL) break;
        node = node->next[invert];
        if(node->score != 0) ret = max(ret, dp(here + i + 1, command) + node->score);
    }
    
    return ret;
}

int solution(string command, vector<string> buttons, vector<int> scores) {
    int sz = buttons.size();
    root = new Node();
    
    for(int i = 0; i < sz; i++) insert(buttons[i], scores[i]);
    for(int i = 0; i < command.size(); i++) cache[i] = -1;
    
    return dp(0, command);
}

int main()
{
    int bts;
    string command;
    vector<string> buttons;
    vector<int> scores;

    cin >> command >> bts;
    for(int i = 0; i < bts; i++) 
    {
        string bt;
        int score;
        cin >> bt >> score;
        buttons.push_back(bt);
        scores.push_back(score);
    }

    cout << solution(command, buttons, scores) << '\n';
}