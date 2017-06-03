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
	ll k;
	vector<ll> a;
	vector<ll> imos;
public:
	Solver();
	void exec();
};

Solver::Solver(){
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

}

void Solver::exec(){

}

int main(){
	Solver solution = Solver();
	solution.exec();
}
