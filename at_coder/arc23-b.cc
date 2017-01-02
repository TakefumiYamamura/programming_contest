#include <iostream>
#include <vector>
#include <algorithm>

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
	// bool oddFlag;
	// if(d % 2 == 0){
	// 	oddFlag = true;
	// }else{
	// 	oddFlag = false;
	// }
	// d = min(r+c-2, d);
	for (int i = 1; i <= d; ++i)
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
	// if(d == r+c-2){
	// 	if(oddFlag){
	// 		cout << dp[d/2 * 2] << endl;
	// 	}else{
	// 		cout << dp[d/2 * 2] << endl;
	// 	}
	// 	return;
	// }
	cout << dp[d] << endl;
}

int main(){
	PersonX px = PersonX();
	px.exec();
}