#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define MOD 1000000007
// INT_MAX
using namespace std;

class Solver
{
private:
	int n;
	int k;
	int m;
	vector<string> strs;
public:
	Solver(){
		cin >> n >> k >> m;
		for (int i = 0; i < n; ++i)
		{
			string tmp;
			cin >> tmp;
			strs.push_back(tmp);
		}
	}
	void exec(){
		for (int i = (m-1)*k; i < min(m*k, n); ++i)
		{
			cout << strs[i] << endl;
		}
	}
};


int main(){


}
