#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class SafeBetting
{
public:
	int minRounds(int a, int b, int c){
		int ans = 0;
		while(c > b){
			b += (b - a);
			ans++;
		}
		return ans;
	}
};
