#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define eps 10e-10

struct Point
{
	int x, y;
};

class UwakiInvestigation
{
public:
	Point start, goal;
	int t, v;
	int n;
	vector<Point> points;
	UwakiInvestigation();
	~UwakiInvestigation();
	void exec();
	double dis(Point a, Point b);
};

UwakiInvestigation::UwakiInvestigation(){
	cin >> start.x >> start.y >> goal.x >> goal.y >> t >> v;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Point tmp;
		cin >> tmp.x >> tmp.y;
		points.push_back(tmp);
	}
}

UwakiInvestigation::~UwakiInvestigation(){}

void UwakiInvestigation::exec(){
	for (int i = 0; i < n; ++i)
	{
		if(dis(start, points[i]) + dis(points[i], goal) - v*t < eps){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

double UwakiInvestigation::dis(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}


int main(){
	UwakiInvestigation ui = UwakiInvestigation();
	ui.exec();

}
