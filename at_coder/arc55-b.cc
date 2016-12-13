#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class Senbei
{
public:
	int n, k;
	Senbei();
	~Senbei();
	void exec();
	int fac(int num);
};

Senbei::Senbei(){
	cin >> n >> k;
}

Senbei::~Senbei(){}

void Senbei::exec(){
	vector<vector<vector<double> > > dp;
	dp.resize(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i].resize(k+1);
		for (int j = 0; j <= k; ++j)
		{
			dp[i][j].resize(2);
			dp[i][j][0] = 0;
			dp[i][j][1] = 0; 
		}
	}
	dp[0][0][0] = 1.0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			dp[i+1][j][0] += ((k+1)-1.0)/(double)(k+1) * dp[i][j][0];
			dp[i+1][j][1] += ((k+1)-1.0)/(double)(k+1) * dp[i][j][1];
			//最大
			dp[i+1][j+1][0] = 1.0/(double)(k+1) * dp[i][j][0] + ((k+1)-1.0)/(double)(k+1) * dp[i][j+1][1];
		    dp[i+1][j+1][1] = 1.0/(double)(k+1) * dp[i][j][0] + ((k+1)-1.0)/(double)(k+1) * dp[i][j+1][1];
		    cout << i+1 << " " << j+1 << " 0 " << dp[i][j][0] << endl;
		    cout << i+1 << " " << j+1 << " 1 " << dp[i][j][1] << endl;
		}
	}
	double ans = 0;
	for (int i = 0; i <= k; ++i)
	{
		ans += dp[n][i][1];
	}
	printf("%.12lf\n", ans);

}

int main(){
	Senbei s = Senbei();
	s.exec();
}