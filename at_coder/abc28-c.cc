#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	 vector<int> nums;
	 for (int i = 0; i < 5; ++i)
	 {
	 	int n;
	 	cin >> n;
	 	nums.push_back(n);
	 }

	 vector<int> ans;
	 for (int i = 0; i < 1<<5; ++i)
	 {
	 	int count = 0;
	 	for (int j = 0; j < 5 ; ++j)
	 	{
	 		if(i >> j & 1){
	 			count++;
	 		}
	 	}
	 	if(count == 3){
	 		int tmp = 0;
	 		for (int j = 0; j < 5; ++j)
	 		{
	 			if(i >> j & 1){
	 				tmp += nums[j];
	 			}
	 		}
	 		ans.push_back(tmp);
	 	}
	 }
	 sort(ans.begin(), ans.end(), greater<int>() );
	 cout << ans[2] << endl;
}
