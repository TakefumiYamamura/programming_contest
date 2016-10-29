#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 1000001
#define ll long long
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(){
	int n;
	ll imos[MAX_N+1];
	Fill(imos, 0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		imos[a]++;
		imos[b+1]--;
	}

    ll ans = imos[0];
	for (int i = 1; i <= MAX_N; ++i)
	{
		imos[i] += imos[i-1];
		ans = max(ans, imos[i]); 
	}

	cout << ans << endl;

}
