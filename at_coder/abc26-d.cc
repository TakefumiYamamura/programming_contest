#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#define eps 10e-7

using namespace std;

class MrTakahashiBall
{
public:
	double a, b, c;
	MrTakahashiBall();
	~MrTakahashiBall();
	double computeF(double t);
	void exec();
};


MrTakahashiBall::MrTakahashiBall(){
	cin >> a >> b >> c;
}

MrTakahashiBall::~MrTakahashiBall(){}

double MrTakahashiBall::computeF(double t){
	return a * t + b * sin(c * t * M_PI);
}

void MrTakahashiBall::exec(){
	double r, l, mid, f_value;
	l = 0;
	r = 20000;
	while(true){
		mid = (r + l)/ 2.0;
		f_value = computeF(mid);
		if(fabs(f_value - 100) < eps) break;
		if(f_value > 100){
			r = mid;
		}else{
			l = mid;
		}
	}
	printf("%.12lf\n", mid );
}


int main(){
	MrTakahashiBall mrb = MrTakahashiBall();
	mrb.exec();
}
