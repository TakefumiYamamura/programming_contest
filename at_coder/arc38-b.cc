#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class ChessGame
{
private:
	int h;
	int w;
	vector<vector<int> > board;
	map<pair<int, int>, bool> dp;
public:
	ChessGame() {
		cin >> h >> w;
		board = vector<vector<int> >(h, vector<int>(w, 0));
		for (int i = 0; i < h; ++i)
		{
			string tmp;
			cin >> tmp;
			for (int j = 0; j < w; ++j)
			{
				if(tmp[j] == '.') board[i][j] = 1;
			}
		}
	}

	bool recursive(int x, int y) {
		pair<int , int> key = make_pair(x, y);
		if(dp.find(key) != dp.end()) return dp[key];
		if(check(x, y) == false) return dp[key] = false;
		//次にいけるマスが一つでも負けマスなら勝ち
		//次にいけるマスが全て勝ちマスなら負け
		bool flag = false;
		if(x + 1 < h) {
			if(board[x+1][y] == 1 && recursive(x+1, y) == false) flag = true;
		}
		if(y + 1 < w) {
			if(board[x][y+1] == 1 && recursive(x, y+1) == false) flag = true;
		}
		if(x + 1 < h && y + 1 < w) {
			if(board[x+1][y+1] == 1 && recursive(x+1, y+1) == false) flag = true;
		}
		dp[key] = flag;
        // dp[key] = !recursive(x + 1, y) || !recursive(x, y + 1) || !recursive(x + 1, y);
		return dp[key];
	}

	//次にいけるマスが一つも無ければfalse
	bool check(int x, int y) {
		bool flag = false;
		if(x + 1 < h) {
			if(board[x+1][y] == 1) flag = true;
		}
		if(y + 1 < w) {
			if(board[x][y+1] == 1) flag = true;
		}
		if(x + 1 < h && y + 1 < w) {
			if(board[x+1][y+1] == 1) flag = true;
		}
		return flag;
	}

	void exec() {
		if(recursive(0, 0)) {
			cout << "First" << endl;
		} else {
			cout << "Second" << endl;
		}
	}
};

int main() {
	ChessGame cg = ChessGame();
	cg.exec();
}
