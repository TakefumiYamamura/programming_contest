#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ChanceGenetater
{
public:
	int n, k;
	string s;
	vector<vector<vector<int> > > dp;
	ChanceGenetater();
	~ChanceGenetater();
	void exec();
};


ChanceGenetater::ChanceGenetater(){
	cin >> n >> k;
	cin >> s;
	dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		dp[i].resize(i);
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j].resize(k+1);
		}
	}
}

ChanceGenetater::~ChanceGenetater(){}

void ChanceGenetater::exec(){
	for (int i = 0; i < s.length(); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			for (int t = 0; t <= k; ++t)
			{
				if(s[i] == '0'){
					dp[i+1][j][k] = dp[i][j][k];
				}else if(s[i] == '1'){
					dp[i+1][j][k] = dp[i][j][k];
				}else{
					dp[i+1][j][k] = dp[i][j][k];
				}
			}
		}
	}
}

int main(){

}
