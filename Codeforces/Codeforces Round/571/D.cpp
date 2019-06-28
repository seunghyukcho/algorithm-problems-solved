#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

double A[100002];
int newA[100002];
int n;

int main()
{
	ll sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		newA[i] = floor(A[i]);
		sum += newA[i];
	}

	for(int i = 0; i < n; i++)
	{
		if(sum != 0 && (double)newA[i] != A[i])
		{
			cout << (int)ceil(A[i]) << '\n';
			sum++;
		}
		else
			cout << newA[i] << '\n';
	}
}