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


class Solver
{
private:
	ll n;
	vector<ll> a;

public:
	Solver(){
		cin >> n;
		a.resize(3 * n);
		for (int i = 0; i < 3 * n; ++i) {
			cin >> a[i];
		}

	}
	void exec(){
		// sort(a.begin(), a.end());
		// ll min_v = 0;
		// ll max_v = 0;
		// for (int i = 0; i < n; ++i)
		// {
		// 	min_v += a[i + n];
		// 	max_v += a[i + 2 * n];
		// }


	}

};

int main(){
	Solver s = Solver();
	s.exec();
}
