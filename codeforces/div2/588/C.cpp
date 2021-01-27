#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

static int n, m, idx[10];
static pair<int, int> edges[100];
static bool visited[10][10];

static bool end()
{
    for(int i = 0; i < n; i++) if(idx[i] != 5) return false;
    return true;
}

static void next()
{
    idx[0]++;
    for(int i = 1; i < n; i++)
    {
        idx[i] += idx[i - 1] / 6; 
        idx[i - 1] %= 6;
    }
}

int main()
{
    int ans = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;

    for(; !end(); next())
    {
        int subans = 0;

        for(int i = 0; i < 6; i++) memset(visited[i], false, sizeof(visited[i]));

        for(int i = 0; i < m; i++)
        {
            auto edge = edges[i];
            int s = idx[edge.first], e = idx[edge.second];

            if(s > e) swap(s, e);
            if(!visited[s][e])
            {
                visited[s][e] = true;
                subans++;
            }
        }

        ans = max(ans, subans);
    }

    cout << ans << '\n';
}