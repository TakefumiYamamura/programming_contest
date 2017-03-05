#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

#define ll long long
#define MOD 1000000007

using namespace std;

std::ifstream ifs("A-large.in");



class Solver
{
public:
	ll r;
	ll c;
	Solver();
	ll exec();
};

Solver::Solver(){
	ifs >> r >> c;
	// cin >> r >> c;
	r--;
	c--;
}


ll Solver::exec(){
	if(r < c) swap(r, c);
	ll ans = 0;
	for (ll i = 1; i <= c; ++i)
	{
		ans += (i * (r- i + 1)% MOD * (c - i + 1)% MOD) % MOD;
		ans %= MOD;
	}
	return ans % MOD;
}

int main(){
	string filename = "test1-b.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	ifs >> testCase;
	// cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		Solver problem = Solver();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

