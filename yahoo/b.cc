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

#define ll long long
#define MOD 1000000007

using namespace std;

class Solver
{
public:
	ll n;
	ll k;
	vector<ll> a;
	Solver(){
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			ll tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		sort(a.begin(), a.end());
	}
	void exec(){
		ll ans = 0;
		ans += (k - 1) * k / 2;
		for (int i = 0; i < k; ++i)
		{
			ans += a[i];
		}
		cout << ans << endl;
	}
};


int main(){
	Solver problem = Solver();
	problem.exec();

}

