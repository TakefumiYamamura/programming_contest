#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

class SuperUserDo
{
public:
	int install(vector<int> a, vector<int> b){
		vector<int> count(1002, 0);
		for (int i = 0; i < a.size(); ++i)
		{
			count[a[i]]++;
			count[b[i]+1]--;
		}
		for (int i = 1; i <= 1000; ++i)
		{
			count[i] += count[i-1];
		}
		int ans = 0;
		for (int i = 1; i <= 1000; ++i)
		{
			if(count[i] > 0) ans++;
		}
		return ans;
	}
};
