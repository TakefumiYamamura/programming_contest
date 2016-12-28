#include <iostream>
#include <vector>

using namespace std;

class TakahashiDatePlan
{
public:
	int n, m
	vector<int> s;
	vector<int> t;
	TakahashiDatePlan();
	~TakahashiDatePlan();
	void exec();
};

TakahashiDatePlan::TakahashiDatePlan(){
	cin >> n >> m;
	s.resize(m);
	t.resize(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> s[i] >> t[i];
	}
}

TakahashiDatePlan::~TakahashiDatePlan(){}

void TakahashiDatePlan::exec(){

}

int main(){
	TakahashiDatePlan tdp = TakahashiDatePlan();
	tdp.exec();
}
