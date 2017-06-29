#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <set>

#define ll long long
#define ull unsigned long long
#define eps 10e-10
#define MOD 1000000007

using namespace std;

struct Object
{
	ll w;
	ll v;
	bool operator < (const Object& x) const {
		if(w == x.w){
			return v > x.v;
		}
		return w < x.w;
	}
};

class SimpleKnapsack
{
private:
	ll n;
	ll max_w;
	vector<Object> objs;
	unordered_map<ll, vector<ll> > w_imos;
	ll min_w;

public:
	SimpleKnapsack(){
		cin >> n >> max_w;
		for (int i = 0; i < n; ++i)
		{
			Object tmp;
			cin >> tmp.w >> tmp.v;
			objs.push_back(tmp);

		}
		min_w = objs[0].w;
		sort(objs.begin(), objs.end());
	}
	void exec(){
		for (int i = 0; i < n; ++i)
		{
			w_imos[objs[i].w].push_back(objs[i].v);
 		}

 		for (auto itr = w_imos.begin(); itr != w_imos.end(); ++itr)
 		{
 			vector<ll> arr = itr->second;
 			for (int i = 1; i < arr.size(); ++i)
 			{
 				 arr[i] += arr[i-1]; 
 			}
 			for (int i = arr.size(); i <= n; ++i)
 			{
 				 arr.push_back(0); 
 			}
 			arr.insert(arr.begin(), 0);
 			itr->second = arr;
 		}

 		ll ans = 0;

 		int size_i = w_imos.find(min_w) == w_imos.end() ? 0 : w_imos[min_w].size(); 
		int size_j = w_imos.find(min_w + 1) == w_imos.end() ? 0 : w_imos[min_w + 1].size();
		int size_k = w_imos.find(min_w + 2) == w_imos.end() ? 0 : w_imos[min_w + 2].size();
		int size_l = w_imos.find(min_w + 3) == w_imos.end() ? 0 : w_imos[min_w + 3].size();

 		for (int i = 0; i <= size_i; ++i)
 		{
 			for (int j = 0; j <= size_j; ++j)
 			{
 				for (int k = 0; k <= size_k; ++k)
 				{
 					for (int l = 0; l <= size_l; ++l)
 					{
 						if(min_w * i + (min_w + 1) * j + (min_w + 2) * k + (min_w + 3) * l  <= max_w){
 							ll val_i = w_imos.find(min_w) == w_imos.end() ? 0 : w_imos[min_w][i]; 
 							ll val_j = w_imos.find(min_w + 1) == w_imos.end() ? 0 : w_imos[min_w + 1][j];
 							ll val_w = w_imos.find(min_w + 2) == w_imos.end() ? 0 : w_imos[min_w + 2][k];
 							ll val_l = w_imos.find(min_w + 3) == w_imos.end() ? 0 : w_imos[min_w + 3][l];
 							ans = max(ans, val_i + val_j + val_w + val_l);
 						}
 					}
 				}
 			}
 		}
 		cout << ans << endl;
	}
};

int main(){
	SimpleKnapsack sk = SimpleKnapsack();
	sk.exec();
}