#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static int N, M, ans;
static bool visited[502];

int main()
{
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if(!visited[b]) ans++;
        visited[b] = true;
    }

    ans = N - ans;
    cout << ans << '\n';
    for(int i = 1; i <= N; i++)
    {  
        if(!visited[i]) cout << i << '\n';
    }
}