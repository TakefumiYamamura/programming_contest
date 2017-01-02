#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct point
{
	double x, y;
};

class InTheSameCircle
{
public:
	int n;
	double minX;
	double minY;
	double maxX;
	double maxY;
	vector<point> points;
	InTheSameCircle();
	~InTheSameCircle();
	void exec();
};

InTheSameCircle::InTheSameCircle(){
	cin >> n;
	minY = 1000000001;
	minX = 1000000001;
	maxX = -1000000001;
	maxY = -1000000001;

	for (int i = 0; i < n; ++i)
	{
		point tmpP;
		double tmpX, tmpY; 
		cin >> tmpX >> tmpY;
		tmpP.x = tmpX/sqrt(2.0) - tmpY/sqrt(2.0);
		tmpP.y = tmpX/sqrt(2.0) + tmpY/sqrt(2.0);
		minX = min(minX, tmpP.x);
		maxX = max(maxX, tmpP.x);
		minY = min(minY, tmpP.y);
		maxY = max(maxY, tmpP.y);
		points.push_back(tmpP);
	}

}

InTheSameCircle::~InTheSameCircle(){}

void InTheSameCircle::exec(){
	double a = (maxX + minX) / 2.0;
	double b = (maxY + minY) / 2.0;
	printf("%.12lf %.12lf\n", (a + b)/sqrt(2.0), (-a + b)/sqrt(2.0) );
}


int main(){
	InTheSameCircle itsc = InTheSameCircle();
	itsc.exec();

}
