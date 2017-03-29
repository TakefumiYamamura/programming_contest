#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class NoNeed
{
private:
	int n, k;
	int sum;
	vector<vector<bool> > l_dp;
	vector<vector<bool> > r_dp;
	vector<int> a;
public:
	NoNeed(){
		cin >> n >> k;
		a.resize(n);
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		l_dp = vector<vector<bool> >(n, vector<bool>(k+1, false));
		r_dp = vector<vector<bool> >(n, vector<bool>(k+1, false));
	}

	bool is_valid(int med){
		if(a[med] >= k){
			return true;
		}

		for (int i = k - a[med]; i < k; ++i)
		{
			if(med == 0){
				if(r_dp[1][i]) return true;
				continue;
			}

			if(med == n-1){
				if(l_dp[n-2][i]) return true;
				continue;
			}

			for (int j = 0; j <= i; ++j)
			{
				if(l_dp[med-1][j] && r_dp[med+1][i-j]){
					return  true;
				}
			}
		}
		return false;
	}

	void set_dp(){
		l_dp[0][0] = true;
		if(a[0] <= k) l_dp[0][a[0]] = true; 
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= k; ++j)
			{
				if(l_dp[i-1][j] || (j - a[i] >= 0 && l_dp[i-1][j - a[i]]) ){
					l_dp[i][j] = true;
				}
			}
		}
		r_dp[n-1][0] = true;
		if(a[n-1] <= k) r_dp[n-1][a[n-1]] = true;
		for (int i = n-2; i >= 0; --i)
		{
			for (int j = 0; j <= k; ++j)
			{
				if(r_dp[i+1][j] || (j -  a[i] >= 0 && r_dp[i+1][j - a[i]]) ){
					r_dp[i][j] = true;
				}
			}
		}

	}

	void exec(){
		sort(a.begin(), a.end());
		// if(sum < k){
		// 	cout << n << endl;
		// 	return;
		// }

		set_dp();
		int left = 0;
		int right = n-1;
		while(left < right){
			int med = (left + right) / 2;
			if(is_valid(med)){
				right = med;
			}else{
				left = med + 1;
			}
		}
		if(is_valid(n-1) == false){
			cout << n << endl;
			return;
		}
		cout << right << endl;
		// for (int i = 0; i < n; ++i)
		// {
		// 	if(is_valid(i)){
		// 		cout << i << endl;
		// 		return;
		// 	}
		// }
		// cout << n << endl;


	}
};


int main(){
	NoNeed nn = NoNeed();
	nn.exec();
}