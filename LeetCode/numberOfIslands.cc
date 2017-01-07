#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<bool > > visited;
	vector<vector<char > > g;
	int x_size;
	int y_size;

	Solution(){}
	void bfs(int x, int y){
		if(visited[x][y]) return;
		visited[x][y] = true;
		if(x + 1 < x_size){
			if(g[x + 1][y] == '1') bfs(x + 1, y);
		}
		if(x - 1 >= 0){
			if(g[x - 1][y] == '1') bfs(x - 1, y);
		}
		if(y - 1 >= 0){
			if(g[x][y - 1] == '1') bfs(x, y - 1);
		}
		if(y + 1 < y_size){
			if(g[x][y + 1] == '1') bfs(x, y + 1);
		}

	}

	int numIslands(vector<vector<char > >& grid) {
		g = grid;
		visited.resize(grid.size());
		x_size = grid.size();
		if(x_size == 0)return 0;
		y_size = grid[0].size();
		for (int i = 0; i < grid.size(); ++i)
		{
			visited[i].resize(grid[i].size());
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if(grid[i][j] == '0'){
					visited[i][j] = true;
				}else{
					visited[i][j] = false;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if(visited[i][j] == 0){
					bfs(i,j);
					ans++;
				}

			}
		}
		return ans;
	}

};

// int main(){
// 	vector<vector<char > > test;
// 	test.resize(3);
// 	test[0].push_back('1');
// 	test[0].push_back('1');
// 	test[0].push_back('0');
// 	test[1].push_back('1');
// 	test[1].push_back('1');
// 	test[1].push_back('0');
// 	test[2].push_back('0');
// 	test[2].push_back('0');
// 	test[2].push_back('1');


// 	Solution s = Solution();
// 	cout << s.numIslands(test) << endl;

// }