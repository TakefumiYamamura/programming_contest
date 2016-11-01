#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const ll MOD = 1e9+7;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll nCk(ll n, ll k){
	int C[30 * 30 + 2];
	int tmp[30 * 30 + 2];
	Fill(C, 0);
	Fill(tmp, 0);
	C[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i+1; ++j)
		{
			tmp[j] = C[j];
		}
		for (int j = 0; j <= i+1; ++j)
		{
			C[j+1] += tmp[j];
			C[j+1] %= MOD;

		}
	}
	C[k] %= MOD;
	return C[k];
}



int main(){
	int r, c, x, y, d, l;
	cin >> r >> c;
	cin >> x >> y;
	cin >> d >> l;

	// ll  dp[30 * 30 + 1][30 * 30 + 1][1 << 4];
	//次元を減らす
	int dp[30 * 30 + 2][(1 << 4)];

	Fill(dp, 0);
	dp[0][0] = 1;

	int dp2[30 * 30 + 2][(1 << 4)];
	Fill(dp2, 0);

	for (int i = 0; i < x * y ; ++i)
	{
		for (int j = 0; j <= d + l ; ++j)
		{
			for (int k = 0; k < (1 << 4); ++k)
			{
				// 上の列
				int bit = k;
				if(i < x){
					bit |= 1 ;
				}
				// 左の列
				if(i%x == 0){
					bit |= 1 << 1;
				}
				//右の列
				if(i%x == x-1){
					bit |= 1 << 2;

				}
				//下の列
				if(i >= x * (y - 1)){
					bit |= 1 << 3;
				} 
				dp2[j][k] += dp[j][k];
				dp2[j][k] %= MOD;
				dp2[j+1][bit] += dp[j][k];
				dp2[j+1][bit] %= MOD;
			}
		}
		for (int j = 0; j <= d + l ; ++j)
		{
			for (int k = 0; k < (1 << 4); ++k)
			{
				dp[j][k] = dp2[j][k];
				// cout << dp[j][k] << " ";
				dp2[j][k] = 0;
 			}
 			// cout << endl;
		}
	}

	ll ans = dp[d + l][(1 << 4) -1] % MOD;

    // cout << dp[d + l][(1 << 4) -1] << endl;
    // cout << (r - x + 1) * (c - y + 1) << endl;
	cout << (r - x + 1) * (c - y + 1) % MOD * dp[d + l][(1 << 4) -1] % MOD * nCk(d+l, min(d, l) ) % MOD << endl;
    // cout << nCk(d+l, d) % MOD << endl;	

}
