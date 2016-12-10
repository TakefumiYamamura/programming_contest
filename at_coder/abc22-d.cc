#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define eps 10e-10

const int counterClockwise = 1;
const int clockwise = -1;


using namespace std;

struct Point{
	double x, y;
	bool operator<(const Point& point) const
    {
    	if(fabs(x - point.x) < eps){
    		return y < point.y;
    	}
        return x < point.x;

    }
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
	double cross(Point a, Point b);
	double andrew(vector<Point> points);
	double distance(Point a, Point b);
	// double findShortestPointPairDistance(vector<Point> points;);
	void exec();
};


BigBang::BigBang(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Point p;
		cin >> p.x >> p.y;
		a1.push_back(p);
	}

	for (int i = 0; i < n; ++i)
	{
		Point p;
		cin >> p.x >> p.y;
		a2.push_back(p);
	}

}

BigBang::~BigBang(){}

double BigBang::cross(Point a, Point b){
	return a.x * b.y - a.y * b.x;
}

int BigBang::ccw(Point a, Point b, Point c){
	b.x -= a.x;
	b.y -= a.y;
	c.x -= a.x;
	c.y -= a.y;
	if(cross(b, c) > 0) return  counterClockwise ; // counter clockwise
	if(cross(b, c) < 0) return  clockwise; // clockwise
	return 0;
}

// double BigBang::findShortestPointPairDistance(std::vector<Point> points){

// }

double BigBang::andrew(vector<Point> points){
	int k = 0;
	sort(points.begin(), points.end());
	vector<Point> convexPoints(2*n);
	// build lower
	for(int i = 0; i < n; ++i)
	{
		while(k >= 2 && ccw(convexPoints[k-2], convexPoints[k-1], points[i]) != counterClockwise) k--;
		convexPoints[k++] = points[i];
	}
	//build upper
	for (int i = n-2, t = k+1; i >= 0; --i)
	{
		while(k >= t && ccw(convexPoints[k-2], convexPoints[k-1], points[i]) != counterClockwise) k--;
		convexPoints[k++] = points[i];
	};
	convexPoints.resize(k);
	double dis = 0;
	for (int i = 0; i < k; ++i)
	{
		dis += distance(points[i], points[i+1]);
	}
	dis += distance(points[k],points[0]);
	return dis;
}

double BigBang::distance(Point a, Point b){
	return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

void BigBang::exec(){
	double ans = andrew(a2) / andrew(a1);
	printf("%.10f\n", ans);
	printf("%.10f\n", andrew(a1));
	printf("%.10f\n", andrew(a2));

}

int main(){
	BigBang bb = BigBang();
	bb.exec();
}
