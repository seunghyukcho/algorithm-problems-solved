#include<iostream>

using namespace std;

int c, n, b[102][102], d[102][102];

int main(){
	for(cin >> c; c > 0; c--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = 0;

		d[0][0] = 1;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				cin >> b[i][j];

				if(i + b[i][j] < n && d[i][j] == 1)
					d[i + b[i][j]][j] = 1;
				if(j + b[i][j] < n && d[i][j] == 1)
					d[i][j + b[i][j]] = 1;
			}

		cout << (d[n - 1][n - 1] == 1 ? "YES" : "NO") << '\n';
	}

	return 0;
}

