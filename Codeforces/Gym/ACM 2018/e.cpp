#include <iostream>

using namespace std;

long long int MAXINT = 1000000007;

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        long long int S = 0, M = 1;
        for(int j = 0; j < N; j++)
        {
            long long int a;
            scanf("%lld", &a);
            S = ((((a%MAXINT) * (S%MAXINT))% MAXINT) + ((((a-1) % MAXINT) * (M%MAXINT))%MAXINT))%MAXINT;
            M *= a;
        }

        printf("%lld\n", S);
    }
    return 0;
}
