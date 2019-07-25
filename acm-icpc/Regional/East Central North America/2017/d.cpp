#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> state(1, 0);
    int egg = 0;
    while(k--)
    {
        string s;
        cin >> s;

        if(s == "undo")
        {
            cin >> s;
            int a = stoi(s);
            while(a--) state.pop_back();
            egg = state.back();
        }
        else
        {
            int a = stoi(s);
            egg += a;
            while(egg < 0) egg += n;
            egg %= n;
            state.push_back(egg);
        }
    }

    cout << state.back() << '\n';

    return 0;
}
