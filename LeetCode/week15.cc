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
    	if(nums.size() == 0){
    		return 0;
    	}
    	int tmp = nums[0];
    	int count0 = 0;
    	int count1 = 0; 
    	int ans = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(tmp == 0 && nums[i] == 0){
    			count0++;
    		}else if(tmp == 1 && nums[i] == 1){
    			count1++;
    		}else{
    			tmp = nums[i];
    			if(nums[i] == 1){
    				count1 = 1;
    				count0 = 0;
    			}else{
    				count0 = 1;
    				count1 = 0;
    			}
    		}
    		ans = max(ans, count1);
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