#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Norm
{
	double x, y, c;
};

class TakahashiNorm
{
public:
	int n;
	vector<Norm> norms;
	TakahashiNorm();
	~TakahashiNorm();
	double dif(Norm a, Norm b);
	void exec();
};

TakahashiNorm::TakahashiNorm(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Norm tmpNorm;
		cin >> tmpNorm.x >> tmpNorm.y >> tmpNorm.c;
		norms.push_back(tmpNorm);
	}
}

TakahashiNorm::~TakahashiNorm(){}

double TakahashiNorm::dif(Norm a, Norm b){
	return (a.c * b.c) / (a.c + b.c) * max(fabs(a.x - b.x), fabs(a.y - b.y));
}

void TakahashiNorm::exec(){
	double ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			ans = max(dif(norms[j], norms[i]) , ans);
		}
	}
	printf("%.12lf\n", ans);
}

int main(){
	TakahashiNorm tn = TakahashiNorm();
	tn.exec();
}
