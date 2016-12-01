#include <iostream>
#include <vector>
using namespace std;

struct Point{
	double x, y;
};


class CutInTwo
{
public:
	int n;
	Point s, e;
	vector<Point> points;

	CutInTwo();
	~CutInTwo();
	bool isRightSide(const Point a, const Point b, const Point o);
	void exec();
	
};

CutInTwo::CutInTwo(){
	cin >> s.x >> s.y;
	cin >> e.x >> e.y;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		double tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		Point p = {tmp_x, tmp_y};
		points.push_back(p);
	}
}

CutInTwo::~CutInTwo(){}

bool CutInTwo::isRightSide(const Point a, const Point b, const Point o){
	return ((a.x - o.x) * (b.y - o.y) - (a.y - o.y)* (b.x - o.x)) > 0;
}

void CutInTwo::exec(){
	points.push_back(points[0]);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if(isRightSide(points[i], e, s) != isRightSide(points[i+1], e, s) && isRightSide(e, points[i], points[i+1]) != isRightSide(s, points[i], points[i+1]) ){
			count++;
		}
	}
	cout << count / 2 + 1 << endl;
}


int main(){
	CutInTwo cit = CutInTwo();
	cit.exec();
}
