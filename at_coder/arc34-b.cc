#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>

#define ll long long

using namespace std;

ll f(ll x) {
	ll ans = 0;
	while(x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> ans;
	for (ll i = max(n - 200, (ll)0); i <= n; ++i)
	{
		if(i + f(i) == n) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(ll x : ans) {
		cout << x << endl;
	}
}
