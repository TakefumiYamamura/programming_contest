#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include <unordered_map>
#define MOD 1000000007
// INT_MAX
using namespace std;


class RemovingParenthesis
{
private:
	unordered_map<string, int> dp;
public:
	int countWays(string s){
		if(dp.find(s) != dp.end()) return dp[s];
		if(s == "") return dp[s] = 1;
		int open = 0;
		int close = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '('){
				open++; 
			}else{
				close++;
				if(open < close){
					return dp[s] = 0;
				}
			}
		}
		bool first_f = false;
		string next_s = s;
		int ans = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '('){
				if(first_f == false){
					next_s.erase(next_s.begin() + i);
				}
				first_f = true;
			}else{
				string next_s2 = next_s;
				next_s2.erase(next_s2.begin() + i - 1);
				ans += countWays(next_s2);
			}
		}
		return dp[s] = ans;
	}
};
