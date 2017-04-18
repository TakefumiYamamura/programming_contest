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

class RepeatNumberCompare
{
public:

	string compare(int x1, int k1, int x2, int k2){
	 	int count1 = 0;
	 	int tmpx1 = x1; 
		while(tmpx1){
			count1++;
			tmpx1 /= 10;
		}
		int count2 = 0;
		int tmpx2 = x2;
		while(tmpx2){
			count2++;
			tmpx2 /= 10;
		}
		count1 *= k1;
		count2 *= k2;
		if(count1 == count2){
			string str1 = "";
			string str2 = "";
			for (int i = 0; i < k1; ++i)
			{
				str1 = str1 + to_string(x1);
			}

			for (int i = 0; i < k2; ++i)
			{
				str2 = str2 + to_string(x2);
			}

			for (int i = 0; i < str1.length(); ++i)
			{
				int r1 = (int)str1[i];
				int r2 = (int)str2[i];
				if(r1 < r2){
					return "Less";
				}else if(r1 > r2){
					return "Greater";
				}
			}
			return "Equal";

		}else if(count1 < count2){
			return "Less";
		}else{
			return "Greater";
		}          
	}
};
