#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#define ll long long
using namespace std;

#define MOD 1000000007

class Solve
{
private:
	int n, c, k;
	vector<int> t;
	int ans; 
public:
	Solve(){
		ans = 0;
		cin >> n >> c >> k;
		t.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> t[i];
		}
		sort(t.begin(), t.end());
	}

	void exec(){
		int itr = 0;
		while(itr < n){
			int new_itr = upper_bound(t.begin(), t.end(), t[itr] + k) - t.begin() - 1;
			// cout << *upper_bound(t.begin(), t.end(), t[itr] + k) << " ";
			int dif = new_itr - itr + 1;
			if(dif > c){
				// ans += dif/c;
				// dif = dif % c;
				ans++;
				itr = itr + c;
				continue;
			}
			if(dif != 0) ans++;
			itr = new_itr+1;
			// cout << itr << " test"<< endl;
		}
		cout << ans << endl;
	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
