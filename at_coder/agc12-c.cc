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
	int n;
	Solver();
	~Solver();
	void exec();
};

Solver::Solver(){
	cin >> n;
}

Solver::~Solver(){}

void Solver::exec(){
	int sum = 0;

	cout << sum << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
