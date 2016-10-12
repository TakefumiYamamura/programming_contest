#include <iostream>
#define ll long long
using namespace std;

int main(){
	ll n, a;
	ll x[51];
	cin >> n >> a;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	ll ans = 0;
	for (int i = 0; i < (1 << n) ; ++i)
	{
		ll tmp = 0;
		ll tmp_count = 0;
		for (int j = 0; j < n; ++j)
		{
			if(i >> j & 1){
				tmp += x[j];
				tmp_count++; 
			}
		}
		if(tmp_count != 0 && tmp == tmp_count * a){
			ans++;
		}
	}
	cout << ans << endl;
}
