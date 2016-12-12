#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define K_MAX 1000000007LL

using namespace std;


class TakahashiGame
{
public:
	int n;
	int k;
	vector<ll> a;
	vector<ll> imos;
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
		ll tmp;
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
	vector<ll> dp;
	dp.resize(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = K_MAX;
	}
	dp[0] = 0;
	dp[1] = 1;	
	for (int i = 1; i < n; ++i)
	{
		vector<ll> tmp;
		tmp.resize(n+1);
		tmp[0] = 0;
		for (int j = 0; j < n; ++j)
		{
			ll min_day = dp[j] *(a[i+1])/ imos[i] + 1;
			if(min_day <= a[i+1]){
				tmp[j+1] = min(dp[j] + min_day, dp[j+1]); 
			}else{
				tmp[j+1] = dp[j+1];
			}
		}
		for (int j = 0; j <= n; ++j)
		{
			dp[j] = tmp[j];
		}
	}
	int ans;
	for (int i = 0; i <= n; ++i)
	{
		if(k >= dp[i]){
			ans = i;
		}
	}
	if(imos[n] == k) ans = 1;
	if(imos[n] == 0) ans = 0;
	cout << ans << endl;
}



int main(){
	TakahashiGame tg = TakahashiGame();
	tg.exec();

}
