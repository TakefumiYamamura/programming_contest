#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

using namespace std;

std::ifstream ifs("input.txt");

class PieProgress
{
public:
	int n;
	int m;
	vector<vector<int> > dp;
	vector<vector<int > > c;
	vector<vector<int > > imos;
	PieProgress();
	~PieProgress();
	int exec();
};

PieProgress::PieProgress(){
	ifs >> n >> m;
	//dp[i][k] i日目にパイを食べたあと通算k個のパイを食べた時の最小値。
	dp.resize(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i].resize(max(n+1,m+1));
		for (int j = 0; j <= max(n+1,m+1); ++j)
		{
			dp[i][j] = INT_MAX/10;
		}
	}

	c.resize(n+1);
	imos.resize(n+1);
	for (int i = 0; i < n; ++i)
	{
		c[i].resize(m+1);
		imos[i].resize(m+1);
		for (int j = 0; j < m; ++j)
		{
			ifs >> c[i][j];
		}
		sort(c[i].begin(), c[i].begin() + m);

		imos[i][0] = 0;
		for (int j = 1; j <= m; ++j)
		{
			// cout << c[i][j] << " ";
			imos[i][j] += imos[i][j-1] + c[i][j-1];
		}
		// cout << endl;
	}
	// 	for (int i = 0; i < n; ++i)
	// {
	// 	// c[i].resize(m+1);
	// 	// imos[i].resize(m+1);
	// 	// for (int j = 0; j < m; ++j)
	// 	// {
	// 	// 	cin >> c[i][j];
	// 	// }

	// 	// imos[i][0] = 0;
	// 	for (int j = 0; j <= m; ++j)
	// 	{
	// 		cout << imos[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

PieProgress::~PieProgress(){}

int PieProgress::exec(){

	for (int j = 0; j <= m; ++j)
	{
		dp[0][j] = imos[0][j] + j*j;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			for (int k = 0; k <= min(m, n); ++k)
			{
				if(j - k >= 0){
					dp[i][j] = min(dp[i][j], dp[i-1][j-k] + imos[i][k] + k*k);
				}
			}
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	return dp[n-1][n];
}

int main(){
	string filename = "test.txt";
	// std::ifstream ifs("input.txt");
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	ifs >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		PieProgress problem = PieProgress();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

