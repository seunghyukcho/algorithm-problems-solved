#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    vector<pair<int, bool> > dots;
    for(int i = 0; i < n ; i++)
    {
        int x;
        scanf("%d", &x);
        dots.push_back(make_pair(x, true));
    }
    for(int i = 0 ;i < m; i++)
    {
        int x;
        scanf("%d", &x);
        dots.push_back(make_pair(x, false));
    }
    sort(dots.begin(), dots.end());
    int min = 1e9, num = 0;
    int dist = 0;
    for(int i = 1 ;i < n+m; i++)
    {
        if(dots[i].second != dots[i-1].second)
        {
            dist = abs(dots[i].first - dots[i-1].first);
            if(min > dist)
            {
                min = dist;
                num = 1;
            }
            else if(min == dist)
            {
                num++;
            }
        }

    }
    printf("%d %d\n", min + abs(c1-c2), num);
}
