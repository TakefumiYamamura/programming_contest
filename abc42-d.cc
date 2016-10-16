#include <iostream>
#define ll long long 
using namespace std;

const ll MOD = 1e9+7;

ll factorial[200003];
ll revfac[200003];
// ll power[200003] = {0};

ll con(ll a, ll b){
	return factorial[a] * revfac[b] % MOD * revfac[a-b] % MOD; 
}

ll pow(ll a, ll e){
	ll tmp = 1;
	while(e > 0){
		if( e%2 != 0){
			tmp = tmp * a % MOD ;
		}else{
			tmp = tmp * tmp % MOD;
		}
		e /= 2; 
	}
	return tmp % MOD;
	// if(e == 0){
	// 	return 1;
	// }
	// if(e%2 == 0){
	// 	return pow(a, e/2) * pow(a, e/2) % MOD;
	// }else{
	// 	return pow(a, e-1) * a % MOD;
	// }
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

int main(){
	ll h, w, a, b;
	cin >> h >> w >> a >> b;

	set_factorial(h+w);
	ll ans = 0;
	for (int i = 0; i <= h-a-1; ++i)
	{
		ans += con(b+i-1, i) * con(w-b+h-i-2, w-b-1) % MOD;
		cout << con(b+i-1, i) <<  " " << con(w-b+h-i-2, w-b-1) << endl;
	}
	cout << ans % MOD << endl;

}