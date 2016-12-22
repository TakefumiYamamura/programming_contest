#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	string t;
	cin >> t;
	int count = 0;
	int ans = 0;
	vector<vector<int > > dp;
	dp.resize(t.length()+1);
	//dp[i][j] jが0なら次にきていいものは2 1なら5

	for (int i = 0; i <= t.length(); ++i)
	{
		dp[i].resize(2);
	}
	dp[0][0] = 0;
	dp[0][1] = -1;
 	for (int i = 0; i < t.length(); ++i)
	{
		if(t[i] == '2'){
			dp[i+1][0] = 0;
			dp[i+1][1] = 1 + dp[i][0];
		}else if(t[i] == '5'){
			dp[i+1][0] = 1 + dp[i][1];
			dp[i+1][1] = -1;
		}else if(t[i] == '?'){
			dp[i+1][0] = 1 + dp[i][1];
			dp[i+1][1] = 1 + dp[i][0];
		}else{
			dp[i+1][0] = 0;
			dp[i+1][1] = -1;
		}
		// cout << dp[i+1][0] <<" " << dp[i+1][1] << endl;
		ans = max(max(ans ,dp[i+1][0]), dp[i+1][1]);
	}

	if(ans < 2){
		ans = 0;
	}

	cout << ans/2 * 2 << endl;

}
