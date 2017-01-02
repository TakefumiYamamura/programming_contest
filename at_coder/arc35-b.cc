#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_N 10011
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
	for (ll i = 1; i <= size; ++i)
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

class ContestAtCoder
{
public:
	ll n;
	vector<ll> t;
	vector<ll> count;
	ContestAtCoder();
	~ContestAtCoder();
	void exec();
};

ContestAtCoder::ContestAtCoder(){
	cin >> n;
	count = vector<ll>(MAX_N, 0);
	for (int i = 0; i < n; ++i)
	{
		ll tmpT;
		cin >> tmpT;
		t.push_back(tmpT);
		count[tmpT]++;
	}

}

ContestAtCoder::~ContestAtCoder(){}

void ContestAtCoder::exec(){
	Conbination c = Conbination(MAX_N);
	sort(t.begin(), t.end());
	for (int i = 1; i < n; ++i)
	{
		t[i] += t[i-1];
	}
	ll sum = 0;
	ll pattern = 1;
	for (int i = 0; i < n; ++i)
	{
		sum += t[i];
	}

	for (int i = 0; i < MAX_N; ++i)
	{
		if(count[i] >= 1){
			pattern = (pattern * c.fac[count[i]] ) % MOD;
		}
	}
	cout << sum << endl;
	cout << pattern << endl;

}

int main(){
	ContestAtCoder cac = ContestAtCoder();
	cac.exec();
}