#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

#define MAX_N 10011
#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

using namespace std;

std::ifstream ifs("input.txt");

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

class BeachUmbrellas
{
public:
	ll n;
	ll m;
	vector<ll > r;
	ll sum_r;
	BeachUmbrellas();
	~BeachUmbrellas();
	ll exec();
};

BeachUmbrellas::BeachUmbrellas(){
	ifs >> n >> m;
	r.resize(n+1);
	sum_r = 0;

	for (int i = 0; i < n; ++i)
	{
		ifs >> r[i];
		sum_r += r[i];
	}
}

BeachUmbrellas::~BeachUmbrellas(){}

ll factional(ll a){
	ll ans = 1;
	for (ll i = 1; i <= a; ++i)
	{
		ans = ((ans % MOD ) * (i % MOD) ) % MOD;
	}
	return ans % MOD;
}

ll BeachUmbrellas::exec(){
	if(n == 1) return m;
	ll ans = 0;
	Conbination c = Conbination(m-sum_r);
	if(m-1-2*sum_r >= 0) ans = (ans + (factional(n) * c.nCk(m-1-2*sum_r + n, n)) % MOD ) % MOD;
	ans %= MOD;
	for (int i = 0; i < n; ++i)
	{
		for (int tmpR = 1; tmpR <= r[i]; ++tmpR)
		{
			if(m-1-2*sum_r+tmpR >= 0){
				ll tmp = (factional(n-1) * c.nCk(m-1-2*sum_r+tmpR + n-1, n-1)) % MOD;
				tmp = (tmp * 2) % MOD;
				ans = (ans + tmp) % MOD;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int tmpRI = 1; tmpRI <= r[i]; ++tmpRI)
			{
				for (int tmpRJ = 1; tmpRJ <= r[j]; ++tmpRJ)
				{
					if(m-1-2*sum_r+ tmpRI + tmpRJ >= 0){
						ll tmp = (factional(n-2) * c.nCk(m-1-2*sum_r+ tmpRI + tmpRJ + n -2, n-2)) % MOD;
						tmp = (tmp * 2) % MOD;
						ans = (ans + tmp) % MOD;
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	string filename = "test.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	ifs >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		BeachUmbrellas problem = BeachUmbrellas();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

