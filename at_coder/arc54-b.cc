#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#define eps 10e-14
using namespace std;

class MooresLaw
{
public:
	long double p;
	MooresLaw();
	~MooresLaw();
	long double Tfunc(long double x);
	void exec();
};

MooresLaw::MooresLaw(){
	cin >> p;
}

MooresLaw::~MooresLaw(){}

long double MooresLaw::Tfunc(long double x){
	return p / pow(2.0, x / 1.50) + x;
}

void MooresLaw::exec(){
	long double left = 0.0;
	long double right = p;
	while(fabs(left - right) > eps){
		long double tmpl = (right + 2 * left) / 3.0;
		long double tmpr = (2 * right + left) / 3.0;
		if(Tfunc(tmpl) < Tfunc(tmpr) ){
			right = tmpr;
		}else{
			left = tmpl;
		}
	}
	printf("%.16Lf\n", Tfunc((left + right)/ 2.0));
}


int main(){
	MooresLaw ml = MooresLaw();
	ml.exec();
}

