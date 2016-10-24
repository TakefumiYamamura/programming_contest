#include <iostream>
#include <vector>
#define NIL -1
#define ll long long 
using namespace std;


vector<ll> G[100001];
ll dp[100001][2];
const ll MOD = 1e9+7;

ll f(int, int);
ll g(int, int);

ll f(int i, int p){
	if(dp[i][0] != NIL) return dp[i][0];
	ll ans = 0;
	ll tmp = 1;
	ans += g(i, p);
	ans %= MOD;

	for (int j = 0; j < G[i].size(); ++j)
	{
		if(G[i][j] != p){
			tmp *= g(G[i][j], i) % MOD;
			tmp %= MOD;
		}
	}
	ans += tmp;
	dp[i][0] = ans % MOD; 
	return ans;
}

ll g(int i, int p){
	if(dp[i][1] != NIL) return dp[i][1];
	ll tmp = 1;
	for (int j = 0; j < G[i].size(); ++j)
	{
		if(G[i][j] != p){
			tmp *= f(G[i][j], i) % MOD;
			tmp %= MOD;
		}
	}
	tmp %= MOD;
	dp[i][1] = tmp;
	return tmp;
}



int main(){
	int N;
	cin >> N;

	for (int i = 0; i < N-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
	{
		dp[i][0] = NIL; //f
		dp[i][1] = NIL; //g
	}

	cout << f(0, -1) % MOD << endl;


}
