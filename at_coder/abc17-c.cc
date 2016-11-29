#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const ll MAX = 1e9+7;

struct Heritage
{
	int l, r;
	int score;	
};

class HighScore
{
public:
	int n;
	int m;
	int sum;
	vector<Heritage> heritages;
	vector<int> imos;
	HighScore();
	~HighScore();
	void exec();
	
};

HighScore::HighScore(){
	cin >> n >> m;
	imos.resize(m+1);
	for (int i = 0; i < imos.size(); ++i)
	{
		imos[i] = 0;
	}
	sum = 0;
	for (int i = 0; i < n; ++i)
	{
		Heritage tmp;
		cin >> tmp.l >> tmp.r >> tmp.score;
		tmp.l--; tmp.r--;
		sum += tmp.score;
		heritages.push_back(tmp);
	}
}

HighScore::~HighScore(){}


void HighScore::exec(){
	for (int i = 0; i < n; ++i)
	{
		imos[heritages[i].l] += heritages[i].score;
		imos[heritages[i].r+1] -= heritages[i].score;
	}
	int min_v = imos[0];
	for (int i = 1; i < m; ++i)
	{
		imos[i] += imos[i-1];
		min_v = min(min_v, imos[i]);
	}
	cout << sum - min_v << endl;
}

int main(){
	HighScore hs = HighScore();
	hs.exec();
}
