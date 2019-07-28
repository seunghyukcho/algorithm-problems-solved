#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

double cache[7][7][7][1002];

int cal(int a, int b, int c){
    if(a==b && b==c){
        return 10000+a*1000;
    }
    else{
        if(a==b){
            return 1000+a*100;
        }
        else if(b==c){
            return 1000+b*100;
        }
        else if(c==a){
            return 1000+c*100;
        }
        else{
            return 100*max(max(a,b),c);
        }
    }
}

double dp(int d1, int d2, int d3, int k)
{
    double& ret = cache[d1][d2][d3][k];
    if(ret != 0.0) return ret;

    ret = cal(d1, d2, d3);
    double mean = 0.0;
    if(k != 0)
    {
        for(int i = 1; i < 7; i++) mean += dp(d2, d3, i, k - 1);
    }

    mean /= 6.0;
    ret = max(ret, mean);

    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);

    double ans = 0.0;
    for(int i = 1; i <= 6; i++)
        for(int j = 1; j <= 6; j++)
            for(int k = 1; k <= 6; k++)
                ans += dp(i, j, k, n - 3);
    ans /= 216;

    printf("%.6lf\n", ans);
}