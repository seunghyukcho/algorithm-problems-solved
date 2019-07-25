#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T;
    for(cin >> T; T > 0; T--)
    {
        int n, num;
        vector<int> planks;

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            planks.push_back(num);
        }

        sort(planks.begin(), planks.end());
        int b1 = planks.back(), b2 = planks[n - 2];

        cout << min(min(b1, b2) - 1, n - 2) << '\n';
    }
}