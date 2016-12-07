#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-10;

struct Point
{
	double x, y;
};

class Vec
{
	double x, y;
	Vec(Point a, Point b){
		x = b.x - a.x;
		y = b.x - a.y;
	}
};

class ClassteringTriangle
{
public:
	long long n;
	vector<Point> points;
	long long cntRA;
	long long cntOA;

	ClassteringTriangle();
	~ClassteringTriangle();
	void exec();
	
};

ClassteringTriangle::ClassteringTriangle(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Point tmpPoint;
		cin >> tmpPoint.x >> tmpPoint.y;
		points.push_back(tmpPoint);
	}
}

ClassteringTriangle::~ClassteringTriangle(){

}

void ClassteringTriangle::exec(){
	cntRA = 0;
	cntOA = 0;
	for (int i = 0; i < n; ++i)
	{
		vector<double> angles;
		for (int j = 0; j < n; ++j)
		{
			if(i == j) continue;
			angles.push_back(atan2(points[j].x - points[i].x, points[j].y - points[i].y) + M_PI);
		}
		sort(angles.begin(), angles.end());
		for (int j = 0; j < n-1; ++j)
		{
			angles.push_back(angles[j] + 2 * M_PI);
		}
		for (int j = 0; j < n-1; ++j)
		{
			cntRA += upper_bound(angles.begin(), angles.end(),angles[j]+ M_PI /2.0 + eps) - lower_bound(angles.begin(), angles.end(),angles[j]+ M_PI /2.0 - eps);
			cntOA += lower_bound(angles.begin(), angles.end(), angles[j]+ M_PI - eps) - upper_bound(angles.begin(), angles.end(),angles[j]+ M_PI/2.0 + eps);
		}
	}
	cout <<  n*(n-1)*(n-2)/6 - cntOA - cntRA << " " << cntRA << " " << cntOA << endl;
}

int main(){
	ClassteringTriangle ct = ClassteringTriangle();
	ct.exec();
}
