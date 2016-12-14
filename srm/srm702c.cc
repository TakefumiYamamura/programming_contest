#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
#define ull unsigned long long
#define ll long long
#define eps 10e-10

class SubsetSumExtreme
{
public:
	double getExpectation(vector<int> block, vector<int> face){
		vector<int> sub_sum;
		for (int i = 0; i < 1<<block.size(); ++i)
		{
			int sum = 0;
			for (int j = 0; j < block.size(); ++j)
			{
				if(i>>j & 1){
					sum += block[j];
				}
			}
			sub_sum.push_back(sum);
		}

		for (int i = 0; i < face.size(); ++i)
		{
			for (int j = 0; j < sub_sum; ++j)
			{
				
			}
		}
	}
};
