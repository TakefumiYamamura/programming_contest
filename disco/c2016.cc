#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX_N 1000001
#define ll long long
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;


// struct table{
// 	int num;
// 	int count;
// };

int main(){
	int n, k;
	cin >> n >> k;
	// ll a[200010];
	vector<table> yakusu;
	vector<ll> a;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		tmp t;
		cin >> t;
		t %= k;
		if(t == 0) ans++;
		a.push_back(t);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < a.length(); ++i)
	{
		tmp t = a[lower_bound(a.begin(), a.end(), a[i])] ;
		// while(a[t])
	}

	// for (int i = 0; i < k; ++i)
	// {
	// 	if(k % i == 0){
	// 		table tmp = {i, 0}
	// 		yakusu.push_back(tmp);
	// 	}
	// }


	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(a[i] * a[j] % k == 0){
				ans++;
			}
		}
		// for (int j = 0; j < yakusu.size(); ++j)
		// {
		// 	if(i % yakusu[j].num == 0){

		// 	}
		// }
	}

	cout << ans << endl;

}
