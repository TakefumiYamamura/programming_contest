#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

#define MAX 1000000001;

int main() {
	int n, k;
	ll c[10002];
	ll dp[10002];
	cin >> n >> k;
	for (int i = 1; i < 10002; ++i)
	{
		dp[i] = MAX;
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	// for (int i = 0; i <= k; ++i)
	// {
	// 	dp[0][i] = c[0];
	// }

	// dp[0] = 0;
	dp[1] = c[1];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i-k-1; j <= i+k+1; ++j)
		{
			if(j < 1 || j > n) continue;
			if(dp[i - k - 1] + c[i] < dp[j]){
				dp[j] = dp[i- k -1] + c[i];
				// cout << dp[i] << " " << i << j << endl;
			}else{
			}
		}
	}

	cout << dp[n] << endl;

 
    return 0;
}
