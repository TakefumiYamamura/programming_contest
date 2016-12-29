#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Area
{
	int x, y;
	static bool Asc(const Area& a1, const Area& a2){
		if(a1.x == a2.x){
			return a1.y < a2.y;
		}else{
			return a1.x < a2.x;
		}
	}
};

class TakahashiDatePlan
{
public:
	int n, m;
	vector<Area> areas;
	vector<long long> imos;
	vector<int> ans;
	TakahashiDatePlan();
	~TakahashiDatePlan();
	void exec();
};

TakahashiDatePlan::TakahashiDatePlan(){
	cin >> n >> m;
	imos.resize(n+1);
	for (int i = 0; i < n+1; ++i)
	{
		imos[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		Area tmp;
		tmp.x = x;
		tmp.y = y;
		areas.push_back(tmp);
		imos[x]++;
		imos[y+1]--;
	}
}

TakahashiDatePlan::~TakahashiDatePlan(){}

void TakahashiDatePlan::exec(){
	for (int i = 0; i < n; ++i)
	{
		imos[i+1] += imos[i];
	}
	int count = 0;
	vector<int> imos_area(n+1, 0);
	for (int i = 0; i < n; ++i)
	{
		if(imos[i] <=1){
			imos[i] = 1;
		}else{
			imos[i] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		imos[i+1] += imos[i]; 
	}
	vector<int> ans;
	for (int i = 0; i < m; ++i)
	{
		if(areas[i].x-1 == -1){
			if(imos[areas[i].y] == 0){
				ans.push_back(i+1);
				count++;
			}
			continue;
		}
		if(imos[areas[i].x-1] == imos[areas[i].y]){
			ans.push_back(i+1);
			count++;
		}

	}
	cout << count <<endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
}

int main(){
	TakahashiDatePlan tdp = TakahashiDatePlan();
	tdp.exec();
}
