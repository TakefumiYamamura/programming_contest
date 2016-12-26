#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MountainData
{
public:
	int n;
	vector<int> h;
	vector<vector<int > > dp;
	MountainData(){
		cin >> n;
		h.resize(n);
		dp.resize(n+1);
		for (int i = 0; i < n; ++i)
		{
			cin >> h[i];
			dp[i].resize(2);
		}
	}
	void exec(){
		int ans = 0;
		dp[0][0] = 1;
		dp[n-1][1] = 1;
		for (int i = 0; i < n-1; ++i)
		{
			if(h[i] < h[i+1]){
				dp[i+1][0] = dp[i][0] + 1;
			}else{
				dp[i+1][0] = 1;
			}		
		}
		for (int i = n-1; i > 0; --i)
		{
			if(h[i-1] > h[i]){
				dp[i-1][1] = dp[i][1] + 1;
			}else{
				dp[i-1][1] = 1;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			// cout << dp[i][0] << " " << dp[i][1] << endl;
			ans = max(ans, dp[i][0] + dp[i][1] - 1);
		}
		cout << ans << endl;
	}
};

int main(){
	MountainData md = MountainData();
	md.exec();
}