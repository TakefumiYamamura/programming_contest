#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream> 
#include <sstream> 

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<vector<int> > dp;
        dp.resize(nums.size()+1);
        for (int i = 0; i <= nums.size(); ++i)
        {
            dp[i].resize(2);
            dp[i][0] = 0;
            dp[i][1] = 0;//0を1にするやつつかった
        }
    	if(nums.size() == 0){
    		return 0;
    	}
    	int ans = 0;
        if(nums[0] == 1){
            dp[0][0] = 1;
        }else{
            dp[0][1] = 1;
        }
        ans = 1;
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i] == 0){
    			// count0++;
                dp[i][0] = 0;
                dp[i][1] += dp[i-1][0] + 1;
    		}else if(nums[i] == 1){
                dp[i][0] += dp[i-1][0] + 1;
                dp[i][1] += dp[i-1][1] + 1; 

    		}
    		ans = max(ans, max(dp[i][0], dp[i][1]));
    	}
    	return ans;
    }
};

// int main(){
// 	Solution s = Solution();
// 	vector<int> test;
// 	test.push_back(1);
// 	test.push_back(0);
// 	test.push_back(1);
// 	test.push_back(1);
// 	test.push_back(0);
// 	test.push_back(1);
// 	cout << s.findMaxConsecutiveOnes(test) << endl;
// }