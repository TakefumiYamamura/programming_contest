#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	double ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	double ans = fabs( ((bx - ax) * (cy - ay) - (by - ay) * (cx - ax) )/ 2.0);
	printf("%.12lf\n", ans );


}
