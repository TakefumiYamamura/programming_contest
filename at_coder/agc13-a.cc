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
	ll n;
	vector<ll> a;
public:
	Solver(){
		cin >> n;
		for (ll i = 0; i < n; ++i)
		{
			ll tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
	}
	void exec(){
		ll ans = 0;
		bool up = true;
		if(a.size() == 1){
			cout << 1 << endl;
			return;
		}
		bool first_flag = true;
		for (ll i = 1; i < n; ++i)
		{
			if(first_flag){
				if(a[i] == a[i-1]) continue;
				if(a[i] > a[i-1]){
					first_flag = false;
					up = true;
				}else{
					first_flag = false;
					up = false;
				}
			}else{
				if(a[i] == a[i-1]) continue;
				if(a[i] > a[i-1]){
					if(up == false){
						ans++;
						first_flag = true;
						// i++;
					}
					up = true;
				}else{
					if(up == true){
						ans++;
						first_flag = true;
						// i++;
					}
					up = false;
				}
			}
		}
		cout << ans + 1<< endl;
	}
};

int main(){
	Solver solution = Solver();
	solution.exec();
}
