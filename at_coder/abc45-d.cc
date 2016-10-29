#include <iostream>
#include <map>
#include <set>
#define ll long long


using namespace std;

ll H, W, N;

int main(){
	cin >> H >> W >> N;
	int a, b;
	map<pair<int, int>, int> mp;

	for (int i = 0; i < N; ++i)
	{
		pair<int, int> p;
		cin >> a >> b;
		mp[pair<int, int>(a-1, b-1) ]++;
		mp[pair<int, int>(a-1, b) ]++;
		mp[pair<int, int>(a, b-1) ]++;
		mp[pair<int, int>(a, b) ]++;
		mp[pair<int, int>(a+1, b+1) ]++;
		mp[pair<int, int>(a+1, b) ]++;
		mp[pair<int, int>(a, b+1) ]++;
		mp[pair<int, int>(a+1, b-1) ]++;
		mp[pair<int, int>(a-1, b+1) ]++;
	}
	ll ans[10] = {0};
	ll size = 0;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr)
	{
		if(itr->first.first > 1 && itr->first.second > 1 && itr->first.first < H && itr->first.second < W ){
			ans[itr->second]++;
			size++;
		}
	}
	ans[0] = (W - 2) * (H - 2) - size;

	for (int i = 0; i < 10; ++i)
	{
		 cout << ans[i] << endl;
	}


}