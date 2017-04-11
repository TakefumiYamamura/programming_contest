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
public:
	ll n;
	ll m;
	vector<ll> x;
	vector<ll> y;
	vector<ll> x_dif;
	vector<ll> y_dif;
	Solver();

	void exec();
};

Solver::Solver(){
	cin >> n >> m;
	x.resize(n);
	y.resize(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 1; i < n; ++i)
	{
		x_dif.push_back(x[i] - x[i-1]);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> y[i];
	}
	for (int i = 1; i < m; ++i)
	{
		y_dif.push_back(y[i] - y[i-1]);
	}
}

void Solver::exec(){
	ll x_sum = 0;
	ll y_sum = 0;
	for (int i = 0; i < n-1; ++i)
	{
		x_sum = (x_sum + (x_dif[i] % mod * ((i+1) * (n-1-i)) % mod) % mod) % mod;
	}
	for (int i = 0; i < m-1; ++i)
	{
		y_sum = (y_sum + (y_dif[i] % mod * ((i+1) * (m-1-i)) % mod) % mod) % mod;
	}
	cout << (x_sum * y_sum) % mod << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
