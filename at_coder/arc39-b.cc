#include <iostream>
#include <vector>
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

class TakahashiKindergarten
{
public:
	int n, k;
	TakahashiKindergarten();
	~TakahashiKindergarten();
	void exec();
	
};

TakahashiKindergarten::TakahashiKindergarten(){
	cin >> n >> k;
}

TakahashiKindergarten::~TakahashiKindergarten(){}

void TakahashiKindergarten::exec(){
	Conbination c = Conbination(n+k+1);
	if(n > k){
		cout << c.nCk(n+k-1, k) % MOD << endl;
		return;
	}
	cout << c.nCk(n, k - k/n *n) << endl;
}

int main(){
	TakahashiKindergarten tk = TakahashiKindergarten();
	tk.exec();
}

