#include <iostream>
#include <algorithm>

using namespace std;

static pair<int, int> probs[12];

int main()
{
    int ans = 0, start = 0;
    for(int i = 0; i < 11; i++) cin >> probs[i].first >> probs[i].second;

    sort(probs, probs + 11);
    for(int i = 0; i < 11; i++)
    {
        ans += (start + probs[i].first) + 20 * probs[i].second;
        start += probs[i].first;
    }

    cout << ans << '\n';
}