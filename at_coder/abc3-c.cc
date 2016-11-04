#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<double> nums;
	double ans = 0.0;

	for (int i = 0; i < n; ++i)
	{
		double tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	std::sort(nums.begin(), nums.end());

	for (int i = n-k; i < n; ++i)
	{
		ans = (ans + nums[i]) / 2.0;
	}

	printf("%.6f\n", ans );

}
