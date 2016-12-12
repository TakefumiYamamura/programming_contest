#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define N_MAX 20001

using namespace std;


class TakahashiGame
{
public:
	int n;
	int k;
	vector<int> a;
	vector<int> imos;
	TakahashiGame();
	~TakahashiGame();
	void exec();
	
};

TakahashiGame::TakahashiGame(){
	cin >> n >> k;
	imos.resize(n+1);
	a.resize(n+1);
	imos[0] = 0;
	a[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		cin >> a[i];
		if(i == 1){
			imos[i] = a[i];
		}else{
			imos[i] = imos[i-1] + a[i];
		}
	}
}

TakahashiGame::~TakahashiGame(){}

void TakahashiGame::exec(){
	vector<int> dp;
	dp.resize(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = N_MAX;
	}
	dp[0] = 0;
	dp[1] = 1;	
	for (int i = 1; i < n; ++i)
	{
		vector<int> tmp;
		tmp.resize(n+1);
		for (int j = 0; j < n; ++j)
		{
			// cout << dp[j] <<endl;
			if(dp[j] == N_MAX) continue;
			// cout << a[i+1] <<endl;
			int min_day = dp[j] *(a[i+1])/ imos[i] + 1;
			// cout << min_day << endl;
			tmp[j+1] = dp[j] + min_day;
			// if(dp[j] + min_day <= imos[i+1] && min_day <= a[i+1]){
			// 	tmp[j+1] = min(dp[j] + min_day, dp[j+1]); 
			// }
		}
		// cout << imos[i] << " "
		for (int j = 0; j <= n; ++j)
		{
			dp[j] = tmp[j];
			// cout << dp[j] << " ";
		}
		// cout << endl;
	}
	int ans;
	for (int i = 0; i <= n; ++i)
	{
		// cout << dp[i] << " " ;
		if(k >= dp[i]){
			ans = i;
		}
	}
	// cout << endl;
	cout << ans << endl;
}



int main(){
	TakahashiGame tg = TakahashiGame();
	tg.exec();

}
