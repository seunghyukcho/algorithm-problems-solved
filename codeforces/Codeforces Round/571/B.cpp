#include <iostream>

using namespace std;

typedef long long ll;

ll solve(int width, int height)
{
	if(width == 1)
		return (height + 1) / 3;

}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << max(solve(n, m), solve(m, n)) << '\n';
}