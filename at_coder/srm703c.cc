#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

using namespace std;

class Conbination
{
public:
	int size;
	vector<ll> fac;
	vector<ll> revfac;
	Conbination(int n);
	~Conbination();
	void setFac();
	ll nCk(ll n, ll k);
	ll pow(ll a, ll e);
};

Conbination::Conbination(int n){
	this->size = n;
	fac.reserve(n+1);
	revfac.reserve(n+1);
	setFac();
}

Conbination::~Conbination(){}

void Conbination::setFac(){
	fac[0] = 1;
	revfac[0] = 1;
	for (int i = 1; i <= size; ++i)
	{
		fac[i] = i * fac[i-1] % MOD;
		revfac[i] = pow(fac[i], MOD - 2) % MOD;
	}
}

ll Conbination::pow(ll a, ll e){
	ll ans = 1;
	while(e > 0){
		if(e & 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		e = e >> 1;
	}
	return ans % MOD;
}

ll Conbination::nCk(ll n, ll k){
	return fac[n] * revfac[k] % MOD * revfac[n - k] % MOD;
}
class ModEquationEasy
{
public:
	int count(int n, int k, int v){
		vector<vector<long long> > dp;
		dp.resize(n+1);
		for (int i = 0; i <= n; ++i)
		{
			dp[i].resize(k+1);
			for (int j = 0; j <= k; ++j)
			{
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < k; ++i)
		{
			dp[0][i] = 1;
		}
		for (long long i = 1; i < n; ++i)
		{
			for (long long j = 0; j < k; ++j)
			{
				for (long long s = 0; s < k; ++s)
				{
					dp[i][j*s%k] = (dp[i][j*s%k] + dp[i-1][j]) % MOD;
				}
			}
		}
		return dp[n-1][v];

	}
};
