#include <iostream>
#include <vector>
using namespace std;

struct Point{
	double x, y;
};

class BigBang
{
public:
	int n;
	vector<Point> a1;
	vector<Point> a2;
	BigBang();
	~BigBang();
	int ccw(Point x, Point y, Point z);
	double cross(Point a, Point b)
	// double findShortestPointPairDistance(vector<Point> points;);
	void exec();
};


BigBang::BigBang(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Point p;
		cin >> p.x >> p.y
		a1.push_back(p);
	}

	for (int i = 0; i < n; ++i)
	{
		Point p;
		cin >> p.x >> p.y
		a2.push_back(p);
	}

}

BigBang::~BigBang(){}

int BigBang::ccw(Point a, Point b, Point c){
	b.x -= a.x;
	b.y -= a.y;
	c.x -= a.x;
	c.y -= a.y;

}

// double BigBang::findShortestPointPairDistance(std::vector<Point> points){

// }

void BigBang::exec(){
	double ans = findShortestPointPairDistance(b) / findShortestPointPairDistance(a);
	printf("%.10f\n", ans);

}

int main()