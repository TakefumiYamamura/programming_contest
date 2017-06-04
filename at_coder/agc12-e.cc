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
	int v;
	int x_s;
	int x_f;
	int y;
	vector<int> x;
	Solver();
	~Solver();
	bool check1(int cur);
	bool check2(int cur);
	void exec();
};

Solver::Solver(){
	cin >> n >> v;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		x.push_back(tmp);
	}
	x_s = x[0];
	x_f = x[n-1];
	y = x[n-1] - x[0];
}

Solver::~Solver(){}

bool Solver::check1(int cur){
	int a = cur - x_s;
	int b = x_f - cur;
	v - a - 2b > 0 ||

}

bool Solver::check2(int cur){

}

void Solver::exec(){
	cout << sum << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
