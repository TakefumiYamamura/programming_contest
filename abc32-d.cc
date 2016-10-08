#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
//INFが小さいとtestcase5で落ちる
#define INF (long long)30000000005
#define ll long long
using namespace std;

int N, W;
ll v[201];
ll v_max = 0; 
ll w[201];
ll ans = 0;


void compute_low_n(){
	//wとvが大きすぎるがnが小さいので半分全列挙で解く
	pair<ll, ll> ps[1 << 16];
	ll sw, sv;
	// 前半の列挙
	int n2 = N/2;
	if(n2 == 0){
		ans = 0;
		return;
	}
	for (int i = 0; i < 1 << n2; ++i)
	{
		sw = 0;
		sv = 0;
		for (int j = 0; j < n2; ++j)
		{
			if(i >> j & 1){
				sw += w[j+1];
				sv += v[j+1];
			}
		}
		ps[i] = make_pair(sw, sv);
	}

	// 無駄な要素の消去
	sort(ps, ps + (1 << n2));
	int m = 1;
	for (int i = 1; i < (1 << n2); ++i)
	{
		if(ps[i - 1].second < ps[i].second){
			ps[m++] = ps[i];
		}
	}

	//後半の列挙
	for (int i = 0; i < (1 << (N - n2) ); ++i)
	{
		sw = 0;
		sv = 0;
		for (int j = 0; j < N - n2; ++j)
		{
			if(i >> j & 1){
				sw += w[n2 + j + 1];
				sv += v[n2 + j + 1];
			}
		}
		if (W >= sw){
			ans = max(ans, sv + (lower_bound(ps, ps+m, make_pair( W - sw, INF)) - 1)->second );
		}
	}

}

void compute_low_v(){
	//dp[i][j]で管理するものはi番目までの商品を使って価値がjの時の重さの最小値
	vector<ll > dp;
	dp = vector<ll>(v_max+1, 0);
	for (int i = 0; i <= v_max; ++i)
	{
		dp[i]= INF;
	}
	dp[0] = 0;

	for (int i = 1; i <= N; ++i)
	{
		//価値の逆順にめぐって小メモリ化
		for (ll j = v_max; j >= 1; --j)
		{
			if(j - v[i] >= 0 && dp[j - v[i]] + w[i] <= W){
				dp[j] = min(dp[j - v[i]] + w[i], dp[j]);
			}
			if(dp[j] <= W){
				ans = max(ans, j);
			}
		}
	}

}

void compute_low_w(){
	vector<vector<ll> > dp;
	dp = vector<vector<ll> >(N+1, vector<ll>(W+1, 0));
	for (int i = 1; i <= N; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= W; ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if(j - w[i] >= 0){
				dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
			ans = max(ans, dp[i][j]);
		}
	}
}


int main(){
	cin >> N >> W;
	v[0] = 0;
	w[0] = 0;
	bool flag_v = true;
	bool flag_w = true;
	ll large_v = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i] >> w[i];
		large_v = max(large_v, v[i]);
		if(v[i] > 1000) flag_v = false;
		if(w[i] > 1000) flag_w = false;
	}
	if(N <= 30){
		compute_low_n();
	}else if(flag_w){
		compute_low_w();
	}else if(flag_v){
	    v_max = large_v * N;
		compute_low_v();
	}
	cout << ans << endl;
}
