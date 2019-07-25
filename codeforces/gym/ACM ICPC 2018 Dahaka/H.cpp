#include <iostream>
#include <map>
using namespace std;

int board[200][200];
int uboard[200][200];
int rboard[200][200];
int dboard[200][200];
int lboard[200][200];

int next_[40000];
bool visited[40000];
long long P = 78294349;

typedef long long ll;
typedef map<ll,ll> mp;

mp factor(ll a)
{
	mp ret;
	while(a>1)
	{
		for(ll i = 2; i <= a; i++)
			if(a%i==0)
			{
				ret[i]++;
				a /= i;
				break;
			}
	}
	return ret;
}

mp lcm(mp a, mp b)
{
	mp ret;

	mp::iterator iter;
	mp::iterator a_end = a.end();
	for(iter = a.begin(); iter != a.end(); iter++)
	{
		ll p = (*iter).first;
		ll r = (*iter).second;
		if(b[p]) ret[p] = max(a[p], b[p]);
		else ret[p] = a[p];
	}
	mp::iterator b_end = b.end();
	for(iter = b.begin(); iter != b.end(); iter++)
	{
		ll p = (*iter).first;
		if(a[p]) continue;
		else ret[p] = b[p];
	}
	return ret;
}

main()
{
	mp::iterator iter;
	/*
	   mp fac = lcm(factor(12),factor(60));
	   for(iter = fac.begin(); iter != fac.end(); iter++)
	   cout << (*iter).first << ' ' << (*iter).second << endl;
	 */
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++)
	{
		int R, C;
		cin >> R >> C;

		int color = 0;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				char a;
				cin >> a;
				if(a=='.') board[i][j] = 0;
				else board[i][j] = ++color;

				uboard[i][j] = rboard[i][j] = dboard[i][j] = lboard[i][j] = 0;
			}
		/*
		   for(int i = 0; i < R; i++)
		   {
		   for(int j = 0; j < C; j++)
		   cout << board[i][j];
		   cout << endl;
		   }
		 */
		// upward
		for(int j = 0; j < C; j++)
		{
			int k = 0;
			for(int i = 0; i < R; i++)
				if(board[i][j])
					uboard[k++][j] = board[i][j];
		}
		// rightward
		for(int i = 0; i < R; i++)
		{
			int k = C-1;
			for(int j = C-1; j >= 0; j--)
				if(uboard[i][j])
					rboard[i][k--] = uboard[i][j];
		}
		// downward
		for(int j = 0; j < C; j++)
		{
			int k = R-1;
			for(int i = R-1; i >=0; i--)
				if(rboard[i][j])
					dboard[k--][j] = rboard[i][j];
		}
		// leftward
		for(int i = 0; i < R; i++)
		{
			int k = 0;
			for(int j = 0; j < C; j++)
				if(dboard[i][j])
					lboard[i][k++] = dboard[i][j];
		}
		/*
		   for(int i = 0; i < R; i++)
		   {
		   for(int j = 0; j < C; j++)
		   cout << lboard[i][j];
		   cout << endl;
		   }
		 */
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				if(board[i][j])
					next_[board[i][j]] = lboard[i][j];

		/*
		   for(int i = 1; i <= color; i++)
		   {
		   cout << i << ' ' << next[i] << endl;
		   visited[i] = false;
		   }
		 */
		mp ans_factor;
		for(int i = 1; i <= color; i++)
			if(!visited[i])
			{
				visited[i] = true;
				ll count = 1;
				int node = next_[i];
				while(node != i)
				{
					count++;
					node = next_[node];
				}
				ans_factor = lcm(ans_factor, factor(count));
			}

		ll ans = 1;
		mp::iterator end = ans_factor.end();
		for(iter = ans_factor.begin(); iter != end; iter++)
		{
			ll p = (*iter).first;
			ll r = (*iter).second;
			while(r--)
			{
				ans *= p;
				ans %= 78294349;
			}
		}

		cout << "Case " << c << ": " << ans%78294349 << '\n';
	}
}
