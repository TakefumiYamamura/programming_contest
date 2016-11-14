#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define N_MAX 100001
#define H_MAX 1e9+1
#define S_MAX 1e9+1
using namespace std;


struct balloon
{
	ll h, s;
	static bool asc(const balloon& x, const balloon& y){
		return (-1) * x.h / x.s > (-1) * y.h / y.s;
	}
};

class ShootingMaster
{
public:
	int n;
	vector<balloon> balloons;

	ShootingMaster();
	~ShootingMaster();
	void binarySearch();
	void exec();
	
};

ShootingMaster::ShootingMaster(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		balloon tmp;
		cin >> tmp.h >> tmp.s;
		balloons.push_back(tmp);
	}
	// sort(balloons.begin(), balloons.end(), balloon::asc);
}

ShootingMaster::~ShootingMaster(){}

void ShootingMaster::binarySearch(){
	ll left = 0;
	// ll right = H_MAX + S_MAX * N_MAX;
	ll right = 1e18;
	ll mid = (right + left) / 2;
	BREAK_LABEL:while(left + 1 < right){
		ll mid = (right + left) / 2;
		vector<double> max_time;
		for (int i = 0; i < balloons.size(); ++i)
		{
			balloon tmp  = balloons[i];
			max_time.push_back(double(mid - tmp.h)/ tmp.s);
		}
		sort(max_time.begin(), max_time.end());
		for (int i = 0; i < balloons.size(); ++i)
		{
			if( (double)i > max_time[i]) {
				left = mid;
				goto BREAK_LABEL;
			}
		}
		right = mid;
	}
	cout << right << endl;
}

void ShootingMaster::exec(){
	binarySearch();
}


int main(){
	ShootingMaster sm = ShootingMaster();
	sm.exec();
}
