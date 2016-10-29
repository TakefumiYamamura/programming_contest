#include <iostream>
#define ll long long 
using namespace std;

int main(){
	ll n;
	ll a[1000001];
	cin >> n;	
	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	a[n] = -1;

	ll l = 0;
	ll ans = 0;
	for (ll r = 0; r < n; ++r)
	{
		if(a[r] >= a[r+1]){
			ans += (r-l+1) * (r-l+2) / 2;
			l = r+1;
		}
	}

	cout << ans << endl;

}
