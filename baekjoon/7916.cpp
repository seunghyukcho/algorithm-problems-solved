#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct Point
{
    ll x, y, z;

    Point operator-(const Point& p)
    {
        return { x - p.x, y - p.y, z - p.z };
    }
} P[100002];

typedef Point Vector;

int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> P[i].x >> P[i].y >> P[i].z;

    if(n <= 3) cout << "TAK\n";
    else
    {
        int pivot = 2;
        Vector v1, v2, v3;
        v1 = P[0] - P[1];
        
        for(; pivot < n; pivot++)
        {
            v2 = P[0] - P[pivot];
            v3 = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };

            if(v3.x == 0 && v3.y == 0 && v3.z == 0) continue;
            break;
        }

        for(int i = pivot + 1; i < n; i++)
        {
            Vector v = P[0] - P[i];
            ll result = v3.x * v.x + v3.y * v.y + v3.z * v.z;

            if(result)
            {
                cout << "NIE\n";
                return 0;
            }
        }

        cout << "TAK\n";
    }
}