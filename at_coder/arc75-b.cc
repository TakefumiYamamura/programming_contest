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

const ll mod = 1e9 + 7;

class Solver
{
private:
	ll n;
	ll a;
	ll b;
	vector<ll> h;
	priority_queue<ll> que;
public:
	Solver();
	bool binary_check(ll times);
	void exec();
};

Solver::Solver(){
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		ll tmp;
		cin >> tmp;
		h.push_back(tmp);
		que.push(tmp);
	}

}

bool Solver::binary_check(ll times){
	priority_queue<ll> q = que;
	ll min_v = b * times;
	ll dif = a - b;
	if(min_v >= q.top()) return true;
	ll count = 0;
	// cout << min_v << " " << que.size() << endl;
	while(!q.empty()) {
		ll cur = q.top();
		q.pop();
		// cout << cur << " ";
		if(cur <= min_v) return true;
		// cout << (cur - min_v + dif) / dif << endl;
		count += (cur - min_v + dif - 1) / dif;
		if(count > times) return false;
	}
	return true;

}

void Solver::exec(){
	ll left = 0;
	ll right = mod;
	while(left + 1 < right){
		ll mid = (left + right) / 2;
		if(binary_check(mid)){
			right = mid;
		}else{
			left = mid;
		}
	}
	// cout << binary_check(800000000) << endl;
	cout << right << endl;

}

int main(){
	Solver solution = Solver();
	solution.exec();
}
