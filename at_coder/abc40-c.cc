#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define N_MAX 100001
#define A_MAX 10001
#define MOD 1000000007
#define ll long long

using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
	int n;
	ll a[N_MAX];
	ll dp[N_MAX];
	Fill(dp, N_MAX * A_MAX);
	dp[0] = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if(i+2 < n){
			dp[i+2] = min(dp[i+2], dp[i] + abs( a[i+2] - a[i]) );
		}
		if(i+1 < n){
			dp[i+1] = min(dp[i+1], dp[i] + abs( a[i+1] - a[i]) );
		}
	}

	cout << dp[n-1] << endl;
}
