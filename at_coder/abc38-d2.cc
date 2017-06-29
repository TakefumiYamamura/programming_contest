#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long 
using namespace std;

struct Present{
	int w, h;
	static bool Asc(const Present& x, const Present& y){
		if(x.w == y.w){
			return x.h > y.h;
		}else{
			return x.w < y.w;
		}
	}
};

class PresentForMySpecial{
private:
	int n;
	vector<Present> presents;
public:
	PresentForMySpecial();
	void exec();
};

PresentForMySpecial::PresentForMySpecial(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Present tmpP;
		cin >> tmpP.w >> tmpP.h;
		presents.push_back(tmpP);
	}
}

void PresentForMySpecial::exec(){
	sort(presents.begin(), presents.end(), Present::Asc);
	vector<int> dp = vector<int>(n+1, INT_MAX);
	for (int i = 0; i < n; ++i)
	{
		auto itr = lower_bound(dp.begin(), dp.end(), presents[i].h);
		*itr = presents[i].h;
	}
	cout << lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin() << endl;

}


int main(){
	PresentForMySpecial pfms = PresentForMySpecial();
	pfms.exec();
}
