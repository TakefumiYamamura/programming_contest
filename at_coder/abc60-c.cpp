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

class Sento
{
private:
	ll n;
	ll t;
	vector<ll> ts;
public:
	Sento(){
		cin >> n >> t;
		ts.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> ts[i];
		}
	}
	void exec(){
		ll sum = t;
		ll end = t;
		for (int i = 0; i < n; ++i)
		{
			if(end > ts[i]){
				sum -= end - ts[i];
			}
			end = ts[i] + t;
			sum += t;
		}
		cout << sum << endl;
	}
};

int main(){
	Sento s = Sento();
	s.exec();
}
