#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char > >& grid) {
    	if(grid.size() == 0){
    		return 0;
    	}
    	int ans = 0;

    	vector<vector<int > > map;
    	map.resize(grid.size());
    	for (int i = 0; i < grid.size(); ++i)
    	{
    		map[i].resize(grid[i].size());
    		for (int j = 0; j < grid[i].size(); ++j)
    		{
    			map[i][j] = 0;
    		}
    	}

    	for (int i = 0; i < grid.size(); ++i)
    	{
    		int hits = 0;
    		for (int j = 0; j < grid[i].size(); ++j)
    		{
    			if(grid[i][j] == 'E'){
    				hits++;
    			}else if(grid[i][j] == 'W'){
    				hits = 0;
    			}
    			map[i][j] += hits;
    		}
    		hits = 0;
    		for (int j = grid[i].size() - 1; j >= 0; --j)
    		{
    			if(grid[i][j] == 'E'){
    				hits++;
    			}else if(grid[i][j] == 'W'){
    				hits = 0;
    			}
    			map[i][j] += hits;
    		}
    	}

    	for (int i = 0; i < grid[0].size(); ++i)
    	{
    		int hits = 0;
    		for (int j = 0; j < grid.size(); ++j)
    		{
    			if(grid[j][i] == 'E'){
    				hits++;
    			}else if(grid[j][i] == 'W'){
    				hits = 0;
    			}
    			map[j][i] += hits;
    		}
    		hits = 0;
    		for (int j = grid.size() - 1; j >= 0; --j)
    		{
    			if(grid[j][i] == 'E'){
    				hits++;
    			}else if(grid[j][i] == 'W'){
    				hits = 0;
    			}
    			map[j][i] += hits;
    		}
    	}

    	for (int i = 0; i < grid.size(); ++i)
    	{
    		for (int j = 0; j < grid[i].size(); ++j)
    		{
    			if(grid[i][j] == '0') ans = max(ans, map[i][j]);
    		}
    	}

    	return ans;
        
    }
};

// int main(){
// 	vector<vector<char > > test;
// 	test.resize(3);
// 	test[0].push_back('0');
// 	test[0].push_back('E');
// 	test[0].push_back('0');
// 	test[0].push_back('0');
// 	test[1].push_back('E');
// 	test[1].push_back('0');
// 	test[1].push_back('W');
// 	test[1].push_back('E');
// 	test[2].push_back('0');
// 	test[2].push_back('E');
// 	test[2].push_back('0');
// 	test[2].push_back('0');
// 	Solution s = Solution();
// 	cout << s.maxKilledEnemies(test) << endl;
// }

