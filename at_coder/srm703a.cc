#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

class SwapAndArithmetic
{
public:
	string able(vector<int> x){
		sort(x.begin(), x.end());
		if(x.size() == 1){
			return "Possible";
		}
		int dif = x[1] - x[0];
		for (int i = 1; i < x.size(); ++i)
		{
			if(x[i]- x[i-1] != dif){
				return "Impossible";
			}
		}
		return "Possible";

	}
};
