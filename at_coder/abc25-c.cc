#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class TwinsGame
{
public:
	int b[4][4];
	int c[4][4];
	int sum;
	map<vector<vector<int> >, int> memo;
	TwinsGame();
	~TwinsGame();
	void exec();
	int recurvisve(vector< vector<int > > board, int turn);
	int calc(vector< vector<int > > board);
};

TwinsGame::TwinsGame(){
	sum = 0;
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 3 ; ++j)
		{
			cin >> b[i][j];
			sum += b[i][j];
		}
	}
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 2 ; ++j)
		{
			cin >> c[i][j];
			sum += c[i][j];
		}
	}
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

//o->1 x->2 chokudai's score is returned
int TwinsGame::calc(vector< vector<int > > board){
	int ans = 0;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 2; ++j)
		{
			if(board[j][i] == board[j+1][i]){
				ans += b[j][i]; 
			}
			if(board[i][j] == board[i][j+1]){
				ans += c[i][j];
			}
		}
	}
	return ans;
}

int TwinsGame::recurvisve(vector< vector<int > > board, int turn){
	if(turn == 9){
		return memo[board] = calc(board);
	}
	if(memo[board] != 0){
		return memo[board];
	}
	int max_ans = -1;
	int min_ans = 1000*12;

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			if(board[i][j] == 0){
				vector<vector<int > > tmp;
				tmp = board;
				if(turn % 2 == 0){
					tmp[i][j] = 1;
					max_ans = max(recurvisve(tmp, turn+1), max_ans);
				}else{
					tmp[i][j] = 2;
					min_ans = min(recurvisve(tmp, turn+1), min_ans);
				}
			}
		}
	}
	if(turn %2 == 0){
		memo[board] = max_ans;
		return max_ans;
	}else{
		memo[board] = min_ans;
		return min_ans;
	}
}

int main(){
	TwinsGame tg = TwinsGame();
	tg.exec();

}
