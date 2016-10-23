#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

double const PI = 3.141592653589793238 ;


struct Point{
	double x, y;
};

Point internallyDivide(const Point &a, const Point &b, double x, double y){
	Point ans;
	ans.x = (b.x * y + a.x * x)/ (x + y);
	ans.y = (b.y * y + a.y * x)/ (x + y);
	return ans;
}

double calculateLength(const Point &a, const Point &b){
	return sqrt( (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) );
}


int main(){
	Point a, b;
	Point z;
	a.x = 1.0;
	a.y = 1.0; 
	b.x = 4.0;
	b.y = 5.0;
	double atob;
	double l = 0.2;
	atob = calculateLength(a, b);
	cout << atob << endl;
	z = internallyDivide(a, b, l, atob - l);
	cout << z.x << " " << z.y << endl;

	Point t;
	t = internallyDivide(a, z, (l - l * tan(22.5 / 180.0 * PI) ), (l * tan(22.5 / 180.0 * PI) ) );
	cout << t.x << " " << t.y << endl;



}


