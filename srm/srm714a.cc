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

class RangeEncoding
{
public:
	int minRanges(vector <int> arr){
		int ans = 1;
		for (int i = 0; i < arr.size() - 1; ++i)
		{
			if(arr[i+1] - arr[i] != 1) ans++;
		}
		return ans;

	}
};
