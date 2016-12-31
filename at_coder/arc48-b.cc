#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

#define MAX_N 100001

using namespace std;

struct player
{
	int r, h;
};


class JankenAtcodr
{
public:
	int n;
	vector<player> players;
	vector<vector<int > > dp;
	vector<int> imos;
	JankenAtcodr();
	~JankenAtcodr();
	void exec();
};

JankenAtcodr::JankenAtcodr(){
	dp.resize(MAX_N);
	imos.resize(MAX_N);
	for (int i = 1; i <= MAX_N; ++i)
	{
		dp[i].resize(3);
		dp[i][0] = 0;
		dp[i][1] = 0;
		dp[i][2] = 0;
		imos[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		player tmpPlayer;
		cin >> tmpPlayer.r >> tmpPlayer.h;
		tmpPlayer.h--;
		players.push_back(tmpPlayer);
		imos[tmpPlayer.r]++;
		dp[tmpPlayer.r][tmpPlayer.h]++;
	}
	for (int i = 0; i < MAX_N; ++i)
	{
		imos[i+1] += imos[i];
	}
}

JankenAtcodr::~JankenAtcodr(){}

void JankenAtcodr::exec(){
	for (int i = 0; i < n; ++i){
		int win = dp[players[i].r][(players[i].h + 1) % 3 ];
		int draw = dp[players[i].r][players[i].h] - 1;
		int lose = dp[players[i].r][(players[i].h + 2) % 3 ];
		cout << imos[players[i].r - 1] + win << " " << imos[MAX_N-1] - imos[players[i].r] + lose << " " << draw << endl; 
	}

}

int main(){
	JankenAtcodr ja = JankenAtcodr();
	ja.exec();
}
