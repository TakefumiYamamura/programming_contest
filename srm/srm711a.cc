#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define MAX_INT 2147483647

using namespace std;

class SquareMaking
{
public:
	int getMinimalPrice(int a, int b, int c, int d){
		int ans = MAX_INT;
		for (int med = 1; med <= 1000000; ++med)
		{
			ans = min(ans, abs(med-a) + abs(med-b) + abs(med-c) + abs(med-d));
		}
		return ans;
	}
};
