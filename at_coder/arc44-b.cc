#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

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

class ShortestPath
{
public:
	int n;
	int maxN;
	vector<ll> a;
	vector<ll> cnt;
	ShortestPath();
	~ShortestPath();
	bool check();
	void exec();
};

ShortestPath::ShortestPath(){
	cin >> n;
	cnt = vector<ll>(n, 0);
	for (int i = 0; i < n; ++i)
	{ 
		int tmpA;
		cin >> tmpA;
		a.push_back(tmpA);
		cnt[tmpA]++;
		maxN = max(maxN, tmpA);
	}
}

ShortestPath::~ShortestPath(){}

bool ShortestPath::check(){
	if(a[0] != 0) return true;
	if(cnt[0] != 1){
		return true;
	}
	for (int i = 0; i <= maxN; ++i)
	{
		if(cnt[i] == 0) return true;
	}
	return false;
}

void ShortestPath::exec(){
	if(check()){
		cout << 0 << endl;
		return;
	}
	Conbination c = Conbination(n+1);
	ll ans = 1;
	for (int i = 1; i <= maxN; ++i)
	{
		ll tmp = ( c.pow(c.pow(2, cnt[i-1]) - 1,  cnt[i]) ) % MOD;
		ans = (ans * tmp) % MOD;
	}
	ll cnt2 = 1;

	for (int i = 1; i <= maxN ; ++i)
	{
		if(cnt[i] >= 2){
			cnt2 = cnt2 * c.pow(2 ,cnt[i] * (cnt[i] - 1 )/ 2 ) % MOD; 
		}
	}
	ans = (ans * cnt2) % MOD;
	cout << ans << endl;
}

int main(){
	ShortestPath sp = ShortestPath();
	sp.exec();
}
