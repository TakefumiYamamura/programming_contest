int tripleStep(int n){
	dp.resize(n, 0);
	if(n < 1) return 0;
	dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		if(i-1 >= 0) dp[i] += dp[i-1];
		if(i-2 >= 0) dp[i] += dp[i-2];
		if(i-3 >= 0) dp[i] += dp[i-3];
	}
	return dp[n-1];
}
