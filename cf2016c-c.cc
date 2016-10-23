#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main(){
	int n;
	ll t[100001];
	ll a[100001];
	ll mint[100001];
	ll mina[100001];
	ll dect[100001];
	ll deca[100001];
	ll ans = 1;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> t[i];
		dect[i] = 0;
		deca[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if(t[n-1] != a[0]){
		cout << 0 << endl;
		return 0;
	}
	ll tmp;
	mint[0] = 1;
	tmp = t[0];
	for (int i = 1; i < n; ++i)
	{
		if(tmp < t[i]){
			mint[i] = 1;
			tmp = t[i];
			dect[i] = t[i];
		}else{
			mint[i] = tmp;
		}
		if(tmp > t[i]){
			cout << 0 << endl;
			return 0;
		}
	}

	mina[n-1] = 1;
	tmp = a[n-1];
	for (int i = n-2; i >= 0; --i)
	{
		if(tmp < a[i]){
			mina[i] = 1;
			tmp = a[i];
			deca[i] = a[i];
		}else{
			mina[i] = tmp;

		}
		if(tmp > a[i]){
			cout << 0 << endl;
			return 0;
		}
		if(dect[i] != 0){
			if(tmp >= dect[i]){

			} else{
				cout << 0 << endl;
				return 0;
			}
		}
	}

	tmp = t[0];
	for (int i = 0; i < n; ++i)
	{
		ans *= min(mint[i], mina[i]) % MOD;
		ans %= MOD;
		if(tmp < t[i]){

			tmp = t[i];
		}
		if(deca[i] != 0){
			if(tmp >= deca[i]){

			} else{
				cout << 0 << endl;
				return 0;
			}
		}
	}

	cout << ans << endl;

}
