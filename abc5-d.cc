#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
#define MAX_N 51
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n;
int q;
int P[52*52];
int dp[52][52];

int cal(int x, int y, int lx, int ly){
	// cout << " "<<dp[lx][ly] << " "<<dp[lx][y] << " "<<dp[x][ly] << " "<<dp[x][y] << " ";
	return dp[lx][ly] - dp[lx][y] - dp[x][ly] + dp[x][y];
}

int solve(int size){
	int ans = 0;
	for (int x = 1; x <= size; ++x)
	{
		if(size % x != 0) continue;
		int y = size / x;
		for (int s = 0; s+x <= n; ++s)
		{
			for (int t = 0; t+y <= n; ++t)
			{
				ans = max( ans, cal(s, t, s+x, t+y) );
				// cout << s << t << "st " << cal(s, t, s+x, t+y) << " xy"<<x<<y<<endl;
			}
		}
	}
	return ans;
}


int main(){
	cin >> n;
	Fill(dp, 0);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> dp[i][j];
		}
	}

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> P[i]; 
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
		}
	}

	int ans[52*52];
	ans[0] = 0;
	for (int i = 1; i <= n*n; ++i)
	{
		ans[i] = max(solve(i), ans[i-1]);
	}
	for (int i = 0; i < q; ++i)
	{
		cout << ans[P[i]] << endl;
	}
}