#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
template<typename A, size_t N, typename T>

void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
	ll n, m;
	bool con[15][15];
	cin >> n >> m;

	Fill(con, false);

	for (int i = 0; i < m; ++i)
	{
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		con[x][y] = true;
		con[y][x] = true;
	}

	ll ans = 0;
	for (int i = 0; i < 1<<n ; ++i)
	{
		vector<ll> v;
		ll tmp = 0;
		for (int j = 0; j < n; ++j)
		{
			if(1 & i>>j){
				v.push_back(j);
				tmp++;
			}
			bool check = true;
			for (int k = 0; k < v.size(); ++k)
			{
				for (int l = k+1; l < v.size(); ++l)
				{
					if(!con[v[k]][v[l]]){
						check = false;
						break;
					}
				}
				if(!check) break;
			}
			if(!check) tmp = 0;
		}
		v.clear();
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}

