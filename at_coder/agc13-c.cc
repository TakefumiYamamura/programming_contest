#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long



class Solver
{
private:
	ll n, l, t;
	vector<ll> x;
	vector<ll> w;
	vector<ll> ans;
	map<int, int> hash;

public:
	Solver(){
		cin >> n >> l >> t;
		for (int i = 0; i < n; ++i)
		{
			ll tmp_x;
			ll tmp_w;
			cin >> tmp_x >> tmp_w;
			x.push_back(tmp_x);
			w.push_back(tmp_w);
			ll tmp_ans;
			if(tmp_w == 1){
				tmp_ans = (tmp_x + t) % l;
			}else{
				tmp_ans = (tmp_x - t) % l;
				if(tmp_ans < 0) tmp_ans += l;
			}
			hash[tmp_ans]++; 
			ans.push_back(tmp_ans);
		}
	}
	void ans_p(){
		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << endl;
		}
	}
	void exec(){
		int ans_num = -1;
		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			if(itr->second == 1) ans_num = itr->first;
		}
		if(ans_num = -1){
			ans_p();
			return;
		}
		int ans_itr = -1;
		for (int i = 0; i < n; ++i)
		{
			if(ans[i] == ans_num){
				ans_itr = i;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << endl;
		}

	}
};

int main(){
	Solver solution = Solver();
	solution.exec();
}
