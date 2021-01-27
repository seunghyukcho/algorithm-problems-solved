#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, A[52][52];
    vector<pair<int, int> > ans;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
            cin >> A[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(A[i][j] == 1)
            {
                bool flag = false; 
                for(int x = 0; !flag && x < 2; x++)
                {
                    for(int y = 0; !flag && y < 2; y++)
                    {
                        if(i + x - 1 < 0 || j + y - 1 < 0 || i + x >= n || j + y >= m) continue;

                        int sum = 0;
                        for(int row = i + x - 1; row < i + x + 1; row++)
                        {
                            for(int col = j + y - 1; col < j + y + 1; col++)
                                sum += A[row][col];
                        }

                        if(sum == 4) 
                        {
                            flag = true;
                            ans.push_back({i + x, j + y});
                        }
                    }
                }

                if(!flag)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }


    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first << ' ' << p.second << '\n';
}