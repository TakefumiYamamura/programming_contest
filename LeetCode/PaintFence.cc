#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
	int numWays(int n, int k){
		if(n == 0 || k == 0) return 0;
		vector<vector<int > > dp;
		dp.resize(n);
		dp[0].resize(2);
		dp[0][0] = k;
		dp[0][1] = 0; 
		for (int i = 1; i < n; ++i)
		{
			dp[i].resize(2);
			dp[i][0] = dp[i-1][0] * (k-1) + dp[i-1][1] * (k-1);
			dp[i][1] = dp[i-1][0];
		}
		return dp[n-1][0] + dp[n-1][1];
	}	
};