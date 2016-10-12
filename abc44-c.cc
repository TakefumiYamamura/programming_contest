#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
	ll n, a;
	ll x[51];
	// ll dp[55][55][2505];
	// dp[i][j][k] 
	// i番目のカードの中からj個選んだ際に合計がkになる場合の数
	cin >> n >> a;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	vector<vector<vector<ll> > > dp;
	dp = vector<vector<vector<ll > > >(n+1, vector<vector<ll > >(n+1, vector<ll >(n*a+10, 0)));  
	dp[0][0][0] = 1;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= i ; ++j)
		{
			for (int k = 0; k <= n*a ; ++k)
			{
				if (i-1>=0 && j-1 >= 0 && k-x[i-1]>= 0)
				{
					dp[i][j][k] += dp[i-1][j-1][k-x[i-1]];
				}
				if(i-1 >= 0){
					dp[i][j][k] += dp[i-1][j][k];
				}
				// cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl; 
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += dp[n][i][i*a];
	}
	cout << ans << endl;
}
