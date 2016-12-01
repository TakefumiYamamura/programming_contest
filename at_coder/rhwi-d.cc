#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct Query
{
	Point p1;
	Point p2;
};

class PatternSolver
{
public:
	int h, w;
	int q;
	vector<Query> qs;

	PatternSolver();
	~PatternSolver();
	void exec();
};

PatternSolver::PatternSolver(){
	cin >> h >> w;

}