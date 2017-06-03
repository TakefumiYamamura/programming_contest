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
	vector<ll> s;
	vector<ll> not_tens;
	// vector<vector<ll>> dp;
	ll sum;
public:
	Solver();
	void exec();
};

Solver::Solver(){
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		s.push_back(tmp);
		sum += tmp;
		if(tmp % 10 != 0) not_tens.push_back(tmp);
	}
	sort(not_tens.begin(), not_tens.end());
}

void Solver::exec(){
	if(not_tens.size() == 0){
		cout << 0 << endl;
		return;
	}
	if(sum % 10 == 0){
		sum -= not_tens[0];
	}
	cout << sum << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
