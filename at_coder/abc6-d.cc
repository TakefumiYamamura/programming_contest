#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

const ll MAX = 1e9+7;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
	ll n;
	ll c[100001];
	cin >> n;
	ll ans = 0;
	ll count = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}
	ll dp[100001];
	Fill(dp, MAX);
	for (int i = 0; i < n; ++i){
		*lower_bound(dp, dp+n, c[i]) = c[i];
	}
	cout << n -distance(dp, lower_bound(dp, dp+n, MAX)) << endl;
	return 0;
}
