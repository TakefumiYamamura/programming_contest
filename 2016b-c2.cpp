#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>

#define ll long long
using namespace std;

int main(){
	ll w, h;
	cin >> w >> h;
	std::vector<pair<ll, ll> > v;
	for (ll i = 0; i < w; ++i)
	{
		ll p;
		cin >> p;
		v.push_back(pair<ll, ll>(p, 0)); 
	}
	for (ll i = 0; i < h; ++i)
	{
		ll q;
		cin >> q;
		v.push_back(pair<ll, ll>(q, 1));
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	ll a = w + 1;
	ll b = h + 1;

	for (ll i = 0; i < w+h; ++i)
	{
		ll tmp;
		if (v[i].second == 0)
		{
			ans += v[i].first * b;
			a--; 
		}else{
			ans += v[i].first * a;
			b--;
		}
	}

	cout << ans << endl;

}
