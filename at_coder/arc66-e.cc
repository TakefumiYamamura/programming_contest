#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

#define MOD 1000000007

class AdditionAndSubtractionHard
{
public:
	int n;
	vector<ll> a;
	vector<string> op;
	vector<vector<ll > > dp;

	AdditionAndSubtractionHard(){
		cin >> n;
		op.push_back("+");
		for (int i = 0; i < 2*n-1; ++i)
		 {
		 	if(i % 2 == 0){
		 		ll tmp;
		 		cin >> tmp;
		 		a.push_back(tmp);
		 	}else{
		 		string tmpOp;
		 		cin >> tmpOp;
		 		op.push_back(tmpOp);
		 	}
		 } 
	}
	void exec(){
		dp.resize(n+1);
		for (int i = 0; i < n; ++i)
		{
			dp[i].resize(2);
			// dp[i][0].resize(2);
			// dp[i][1].resize(2);
		}
		dp[0][0] = a[0];
		dp[0][1] = -1 * MOD; // dp[n][1]の時は、符号が反対になっている。
		int flag = 0;

		for (int i = 1; i < n; ++i)
		{
			if(op[i] == "+"){
				dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] - a[i]);
				dp[i][1] = dp[i-1][1] - a[i];
				if(flag) {
					dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i]);
					dp[i][1] = max(dp[i-1][1] + a[i], dp[i][1]);
				}

			}else{
				dp[i][0] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
				dp[i][1] = max(dp[i-1][1] + a[i], dp[i-1][0] - a[i]);
				if(flag >= 2 ) {
					dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i]);
					dp[i][1] = max(dp[i-1][0] + a[i], dp[i][1]);
				}

				flag++;
			}
			// cout << dp[i][0] << " " << dp[i][1] << endl;
		}

		cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	}
};

int main(){
	AdditionAndSubtractionHard aash = AdditionAndSubtractionHard();
	aash.exec();
}
