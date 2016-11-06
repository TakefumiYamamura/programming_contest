#include <iostream>
#define MOD 1000000007
#define ll long long
#define MAX_N 200003
using namespace std;

template<typename A, size_t N, typename T>

void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll fac[MAX_N];
ll revfac[MAX_N];

// ll nCk(ll n, ll k){
// 	ll array[200001];
// 	array[0] = 1;

// 	for (int i = 0; i < n; ++i)
// 	{
// 		ll tmp[200001];
// 		Fill(tmp, 0);
// 		for (int j = 0; j < i+1; ++j)
// 		{
// 			tmp[j] += array[j];
// 			tmp[j+1] += array[j];
// 			tmp[j] %= MOD; tmp[j+1] %= MOD;
// 		}

// 		for (int j = 0; j <= i+1; ++j)
// 		{
// 			array[j] = tmp[j];
// 			// cout << array[j] << " ";
// 		}
// 		// cout << endl;
// 	}
// 	return array[k];
// }

ll nCk(ll n, ll k){
	return fac[n] * revfac[k] % MOD * revfac[n - k] % MOD;
}

ll pow(ll a, ll e){
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

void set_fac(){
	fac[0] = 1;
	fac[1] = 1;
	revfac[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
	{
		fac[i] = i * fac[i-1] % MOD;
		revfac[i] = pow(fac[i], MOD - 2) % MOD;
	}
}

int main(){
	ll w, h;
	cin >> w >> h;
	set_fac();
	cout << nCk(w + h - 2, w - 1) << endl;
}
