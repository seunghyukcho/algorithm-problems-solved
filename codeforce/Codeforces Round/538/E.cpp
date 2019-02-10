#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#define MAX 1000000000
int getQuery1(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int getQuery2(int k)
{
	printf("> %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

bool v[1000010];
std::vector<int> num;

int main()
{
	srand(time(NULL));
	int a;
	scanf("%d",&a);
	
	int min = 0, max = MAX;
	int val = MAX;
	while(min+1<max)
	{
		int h = (min+max)/2;
		int s = getQuery2(h);
		if(s==1) min = h;
		else
		{
			val = h;
			max = h;
		}
	}
	// if(val > max) val = max;
	
	int d = 0;
	
	for(int i=1;i<=std::min(30, a);i++)
	{
		long long next = 1;
		while(v[next])
		{
			next = (rand() * (long long)rand()) % (long long)a + 1;
		}

		v[next] = true;
		int s = getQuery1(next);
		int t = val-s;
		num.push_back(s);
		d = gcd(d,t);
	}
	std::sort(num.begin(), num.end());
	for(int i = 0; i < num.size() - 1; i++)
	{
		d = gcd(d, num[i + 1] - num[i]);
	}

	printf("! %d %d\n",val-(a-1)*d,d);
	fflush(stdout);
}