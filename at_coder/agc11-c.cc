#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#define ll long long
using namespace std;

#define MOD 1000000007

class Solve
{
private:
	int n;
	vector<ll> a;
	ll ans;

public:
	Solve(){
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
	}

	void exec(){
		ll imos = 0;
		ans = 0;
		for (int i = 0; i < n-1; ++i)
		{
			imos += a[i];
			if(imos * 2 >= a[i+1]){
				ans++;
			}else{
				ans = 0;
			}
		}
		ans++;

		cout << ans << endl;
	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
