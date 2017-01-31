#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Point
{
	int x, y, depth;
	string str;
};

class StepsConstruct
{
public:
	string construct(vector<string> board, int k){
		int n = board.size();
		int m = board[0].length();
		if(k % 2 != (n+m) % 2) return "";
		if(board[0][0] == '#') return "";

		Point s = {0, 0, 0, ""};
		queue<Point> q;
		q.push(s);
		vector<vector<bool > > check;
		check.resize(n);
		for (int i = 0; i < n; ++i)
		{
			check[i].resize(m);
			for (int j = 0; j < m; ++j)
			{
				check[i][j] = false;
			}
		}
		Point ans;
		bool findF = false;
		check[0][0] = true;

		while(!q.empty()){
			Point cur = q.front();
			// cout << cur.x << " "<<cur.y << endl;
			q.pop();
			if(cur.depth > k) continue;
			if(cur.x + 1 < n){
				if(board[cur.x+1][cur.y] == '.' && check[cur.x+1][cur.y] == false){
					Point next = {cur.x+1, cur.y, cur.depth+1, cur.str + "D"};
					q.push(next);
					check[cur.x+1][cur.y] = true;
				}
			}
			if(cur.y + 1 < m){
				if(board[cur.x][cur.y + 1] == '.' && check[cur.x][cur.y + 1] == false){
					Point next = {cur.x, cur.y + 1, cur.depth+1, cur.str + "R"};
					q.push(next);
					check[cur.x][cur.y+1] = true;
				}
			}
			if(cur.x-1 >= 0){
				if(board[cur.x-1][cur.y] == '.' && check[cur.x-1][cur.y] == false){
					Point next = {cur.x-1, cur.y, cur.depth+1, cur.str + "U"};
					q.push(next);
					check[cur.x-1][cur.y] = true;
				}
			}
			if(cur.y-1 >= 0){
				if(board[cur.x][cur.y-1] == '.' && check[cur.x][cur.y-1] == false){
					Point next = {cur.x, cur.y-1, cur.depth+1, cur.str + "L"};
					q.push(next);
					check[cur.x][cur.y-1] = true;
				}
			}
			if(cur.x == n-1 && cur.y == m-1){
				ans = cur;
				findF = true;
				break;
			}

		}
		if(findF == false) return "";
		if(ans.depth == k) return ans.str;
		int tmpC = (k - ans.depth) / 2;
		if(board[n-2][m-1] == '.'){
			for (int i = 0; i < tmpC; ++i)
			{
				ans.str += "UD";
			}
		}else{
			for (int i = 0; i < tmpC; ++i)
			{
				ans.str += "LR";
			}
		}
		return ans.str;
	}
};

// int main(){
// 	vector<string> board;
// 	StepsConstruct s;
// 	board.push_back("...#.");
// 	board.push_back("..#..");
// 	board.push_back(".#...");
// 	s.construct(board,100);
// }
