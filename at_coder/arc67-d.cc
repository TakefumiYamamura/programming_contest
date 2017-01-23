#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

class WalkAndTeleport
{
public:
	long long n, a, b;
	vector<long long>x;
	WalkAndTeleport();
	~WalkAndTeleport();
	void exec();
};

WalkAndTeleport::WalkAndTeleport(){
	cin >> n >> a >> b;
	x.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}

}

WalkAndTeleport::~WalkAndTeleport(){}

void WalkAndTeleport::exec(){
	long long ans = 0;
	for (int i = 1; i < n; ++i)
	{
		ans += min(a*(x[i] - x[i-1]), b);
	}
	cout << ans << endl;
}

int main(){
	WalkAndTeleport wat = WalkAndTeleport();
	wat.exec();
}
