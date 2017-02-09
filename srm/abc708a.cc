#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Cross
{
public:
	string exist(vector<string> board){
		for (int i = 1; i < board.size() - 1; ++i)
		{
			for (int j = 1; j < board[i].length() - 1; ++j)
			{
				string tmp = board[i];
				if(tmp[j] == '#' && tmp[j+1] == '#' && tmp[j-1] == '#'){
					string tmp1 = board[i-1];
					string tmp2 = board[i+1];
					if(tmp1[j] == '#' && tmp2[j] == '#') return "Exist";
				}
			}
		}
		return "Does not exist";
	}
};
