#include <iostream>
#define ll long long 
using namespace std;

const ll MAX = 1e9+7;

ll factorial[200003];

ll con(ll a, ll b){
	return factorial[a]/(factorial[b]*factorial[a-b] % MAX) % MAX; 
}

void set_factorial(ll n){
	factorial[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		factorial[i] = factorial[i-1] * i % MAX;
		factorial[i] %= MAX;

	}
}

int main(){
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	set_factorial(h+w);
	ll ans = 0;
	for (int i = 0; i <= h-a-1; ++i)
	{
		ans += con(b+i-1, i) * con(w-b+h-i-2, w-b-1) % MAX;
		// cout << ans << endl;
		ans = ans%MAX;
	}
	cout << ans % MAX << endl;

}