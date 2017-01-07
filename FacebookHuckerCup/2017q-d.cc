#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class TwinsGame
{
public:
	TwinsGame();
	~TwinsGame();
	void exec();
};

TwinsGame::TwinsGame(){

}

TwinsGame::~TwinsGame(){}

void TwinsGame::exec(){
	vector<vector<int > > board;
	board.resize(4);
	for (int i = 1; i <= 3; ++i)
	{
		board[i].resize(4);
		for (int j = 1; j <= 3; ++j)
		{
			board[i][j] = 0;
		}
	}
	int chokudai = recurvisve(board, 0);
	int chokuko = sum - chokudai;
	cout << chokudai << endl;
	cout << chokuko << endl;
}



int main(){
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		cout << "Case #" << i+1 << ": ";
		TwinsGame problem = TwinsGame();
		problem.exec();
	}

}
