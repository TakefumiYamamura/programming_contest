#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define MOD 1000000007
// INT_MAX
using namespace std;

class Saleswoman
{
public:
	 int minMoves(vector <int> pos, vector <int> delta){
	 	int cur = 0;
	 	int ans = pos[pos.size() - 1];
	 	queue<int> again;
	 	for (int i = 0; i < delta.size(); ++i)
	 	{
	 		cur += delta[i];
	 		if(cur < 0){
	 			if(delta[i] < 0){
	 				again.push(pos[i]);
	 			}
	 		}else{
	 			bool flag = true;
	 			while(!again.empty()){
	 				int cur = again.front();
	 				again.pop();
	 				if(flag) ans += 2 * (pos[i] - cur);
	 				flag = false;
	 			}
	 		}
	 	}
	 	return ans;
	}
};
