#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define ll long long 
using namespace std;

const ll MOD = 1e9+7;

// ll factorial[200003];
// ll revfac[200003];

// ll con(ll a, ll b){
// 	return factorial[a] * revfac[b] % MOD * revfac[a-b] % MOD; 
// }

ll pow(ll a, ll e){
	ll tmp = 1;
	while(e > 0){
		if( e & 1ll){
			tmp = tmp * a % MOD ;
		}
		a = a * a % MOD;
		e >>= 1; 
	}
	return tmp;
}


void set_factorial(ll n){
	factorial[0] = 1;
	revfac[0] = 1; 
	for (int i = 1; i <= n; ++i)
	{
		factorial[i] = factorial[i-1] * i % MOD;
		revfac[i] = pow(factorial[i], MOD - 2) % MOD;
	}
}

ll factorial( ll x )
{
	ll tmp = x;
	for( ll i = 1; i < x-1 ;++i ){
		tmp *= x-i;
		tmp %= MOD;
	}
	return tmp % MOD;
	
}


int main(){
	ll n;
	cin >> n;
	int p[500001];
	set<int> data;
	vector<int> shortage;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		data.insert(p[i])
	}
	for (int i = 1; i <= n; ++i)
	{
		if(set.find(i) == false){
			shortage.push_back(i);
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		
	}
	for (int i = 0; i < n; ++i)
	{
		if(p[i] == 0){
			for (int i = 0; i < shortage.length(); ++i)
			{
				ans += pow(2, n-i-1);
				ans %= MOD;
			}
		}
	}
	ll fac = factorial(shortage.length());


	cin >> h >> w >> a >> b;

	set_factorial(h+w);
	ll ans = 0;
	for (int i = 0; i <= h-a-1; ++i)
	{
		ans += con(b+i-1, i) * con(w-b+h-i-2, w-b-1) % MOD;
	}
	cout << ans % MOD << endl;
}
