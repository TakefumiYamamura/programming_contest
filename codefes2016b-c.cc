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
	ll w, h;
	vector<ll> p;
	vector<ll> q;

public:
	Solve(){
		cin >> w >> h;
		for (ll i = 0; i < w; ++i)
		{
			ll tmp;
			cin >> tmp;
			p.push_back(tmp);
		}
		for (ll i = 0; i < h; ++i)
		{
			ll tmp;
			cin >> tmp;
			q.push_back(tmp);
		}
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());

	}

	void exec(){
		ll i1 = 0;
		ll i2 = 0;
		ll ans = 0;
		for (ll i = 0; i < w + h; ++i)
		{
			if(i1 == w) {
				ans += q[i2] * (w - i1 + 1);
				i2++;
				continue;
			}

			if(i2 == h) {
				ans += p[i1] * (h - i2 + 1);
				i1++;
				continue;
			}

			if(p[i1] < q[i2]) {
				ans += p[i1] * (h - i2 + 1);
				i1++;
			} else {
				ans += q[i2] * (w - i1 + 1);
				i2++;
			}
		}

		cout << ans << endl;
	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
