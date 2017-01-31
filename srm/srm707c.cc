#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class Cashback
{
public:
	double findMax(vector<int> limit, vector<int> rate, vector<int> amount){
		int ans = 1;
		int tmp = 1;
		for (int i = 0; i < s.length()-1; ++i)
		{
			if(s[i] != s[i+1]){
				tmp += 1; 
				ans = max(tmp, ans);
			}else{
				tmp = 1;
			}
		}
		return ans;
	}
};
