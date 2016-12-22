#include <iostream>
#include <vector>
using namespace std;

class SkiLift
{
public:
	int n;
	vector<int> a;
	vector<int> map;
	SkiLift();
	void exec();
	
};

SkiLift::SkiLift(){
	cin >> n;
	a.resize(n);
	map.resize(5);
	for (int i = 0; i <= 4 ; ++i)
	{
		map[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		map[a[i]]++;
	}
}

void SkiLift::exec(){
	int ans = 0;
	ans += map[4];
	ans += map[3];
	map[1] = max(map[1] - map[3], 0);
	ans += map[2] / 2;
	if(map[2] % 2 == 1){
		ans++;
		map[1] = max(map[1] - 2, 0);
	}
	ans += map[1]/4;
	if(map[1] % 4 != 0){
		ans++;
	}
	cout << ans << endl;
}

int main(){
	SkiLift sl = SkiLift();
	sl.exec();
}
