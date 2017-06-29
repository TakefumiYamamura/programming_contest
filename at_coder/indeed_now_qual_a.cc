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
public:
	string a, b;
	Solver(){
		cin >> a >> b;
	}
	void exec(){
		cout << a.length() * b.length() << endl;
	}
};

int main(){
	Solver s = Solver();
	s.exec();
}