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

class CodingContestCreattion
{
public:
	int n;
	vector<int> d;
	vector<vector<int> > dp;
	CodingContestCreattion();
	~CodingContestCreattion();
	void exec();
};

CodingContestCreattion::CodingContestCreattion(){
	cin >> n;
	d.resize(n);
	dp.resize(n+1);
	for (int i = 0; i <= n; ++i)
	{
		dp[i].resize(4);
		for (int j = 0; j < 4; ++j)
		{
			dp[i][j] = 0;
		}

	}
	for (int i = 0; i < n; ++i)
	{
		cin >> d[i];
	}

}

CodingContestCreattion::~CodingContestCreattion(){}

int CodingContestCreattion::exec(){
	int cur = d[0];
	int count = 0;
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if(d[i] > cur + 10){
			d[i] += 
		}
	}

}

int main(){
	string filename = "test.txt";
	ofstream writing_file;
    writing_file.open(filename, std::ios::out);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		CodingContestCreattion problem = CodingContestCreattion();
		writing_file << "Case #" << i+1 << ": " << problem.exec() << endl;
	}

}

