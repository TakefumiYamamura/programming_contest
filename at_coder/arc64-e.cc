#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};

struct Circle
{
	Point center;
	int radius;
};

class CosmicRays
{
public:
	Point start, end;
	int n;
	vector<vector<int> > adjacent;
	vector<Circle> circles;
	CosmicRays();
	~CosmicRays();
	void exec();
};

CosmicRays::CosmicRays(){
	cin >> start.x >> start.y >> end.x >> end.y;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Circle tmpCircle;
		cin >> tmpCircle.point.x >> tmpCircle.point.y >> tmpCircle.radius;
		circles.push_back(tmpCircle);
	}
}

CosmicRays::~CosmicRays(){}

void CosmicRays::exec(){}

int main(){
	
}
