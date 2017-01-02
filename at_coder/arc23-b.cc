#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

class PersonX
{
public:
	int r, c, d;
	vector<int> dp;
	vector<vector<int> > a;
	PersonX();
	~PersonX();
	void exec();
};

PersonX::PersonX(){
	cin >> r >> c >> d;
	a.resize(r);
	for (int i = 0; i < r; ++i)
	{
		a[i].resize(c);
		for (int j = 0; j < c; ++j)
		{
			cin >> a[i][j];
		}
	}
	dp = vector<int>(d+1, 0);
}

PersonX::~PersonX(){}

void PersonX::exec(){
	for (int i = 0; i <= d; ++i)
	{
		if(i-2 >= 0) dp[i] = dp[i-2];
		for (int j = 0; j < r; ++j)
		{
			int tmp = i-j;
			if(tmp < c && 0 <= tmp){
				dp[i] = max(dp[i], a[j][tmp]);
			}
		}
	}
	cout << dp[d] << endl;
}

int main(){
	PersonX px = PersonX();
	px.exec();
}