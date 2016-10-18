#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin >> n;
	ll ten[10];
	ten[0] = 1;
	for (int i = 1; i < 10; ++i)
	{
		ten[i] = 10 * ten[i-1]; 
		
	}
	ll ans = 0;

	for (int i = 0; i < 9; ++i)
	{
		ans += ten[i] * (n / ten[i+1]);
		ll tmp = n % ten[i+1];
		if(tmp < ten[i]) continue;
		if(ten[i] <= tmp && tmp < 2*ten[i] ){
			ans += tmp - ten[i]+1;
			continue;
		}
		if(tmp > ten[i]){
			ans += ten[i];
			continue;
		}
	}
	cout << ans << endl;

}
