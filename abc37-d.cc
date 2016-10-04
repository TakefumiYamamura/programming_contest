#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int h, w;
int a[1001][10001];
int f[1001][10001];
const int MOD = 1e9 + 7;
ll ans = 0;

bool check_limit(int i, int j){
	if(i >= h || i < 0) return false;
	if(j >= w || j < 0) return false;
	return true;
}

int dp(int i, int j){
	if(f[i][j] != 0){
		return f[i][j];
	}
	ll tmp = 0;
	if(check_limit(i, j+1) && a[i][j+1] > a[i][j]){
		tmp += dp(i, j+1); 
	}
	if(check_limit(i+1, j) && a[i+1][j] > a[i][j]){
		tmp += dp(i+1, j); 
	}
	if(check_limit(i, j-1) && a[i][j-1] > a[i][j]){
		tmp += dp(i, j-1); 
	}
	if(check_limit(i-1, j) && a[i-1][j] > a[i][j]){
		tmp += dp(i-1, j); 
	}
	f[i][j] = (tmp + 1) % MOD;
	return f[i][j];
}


int main(){
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> a[i][j];
			f[i][j] = 0;
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			ans += dp(i, j);
			ans %= MOD;
		}
	}

	cout << ans % MOD << endl;
	return 0;
}
