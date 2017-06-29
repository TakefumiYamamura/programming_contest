#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

class Solver
{
public:
	ll n;
	vector<ll> a;
	map<ll, ll>hash;
	Solver();
	~Solver();
	void exec();
};

Solver::Solver(){
	cin >> n;
	for (int i = 0; i < 3*n; ++i)
	{
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
		hash[tmp]++;
	}
}

Solver::~Solver(){}

void Solver::exec(){
	ll sum = 0;
	sort(a.begin(), a.end(), greater<ll>());
	for (int i = 0; i < n; ++i)
	{
		sum += a[2*i+1];
	}
	cout << sum << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
