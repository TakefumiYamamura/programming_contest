#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		multimap<int, int> hash;
		pair<int, int>p;
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i)
		{
			hash.insert(make_pair(nums[i], i));
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			int cnt = hash.count(target - nums[i]);
			if(cnt == 0) continue;
			if(cnt == 1 && nums[i] != target - nums[i]){
				ans.push_back(hash.find(nums[i])->second);
				ans.push_back(hash.find(target - nums[i])->second);
				return ans;
			}
			if(cnt == 2 && nums[i] == target - nums[i]){
				multimap<int, int>::iterator it = hash.find(target - nums[i]);
				ans.push_back(it->second);
				it++;
				ans.push_back(it->second);
				return ans;
			}
		}
		return ans;
	}
	
};
