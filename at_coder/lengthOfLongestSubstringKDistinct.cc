#include <cmath>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	Solution(){}
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    	int ans = 0;
    	int difCount = 0;
    	map<char, int> hash;
    	int j = 0;
    	for (int i = 0; i < s.length(); ++i)
    	{
    		if(hash[s[i]] == 0){
    			difCount++;
    		}
    		hash[s[i]]++;
    		while(difCount > k){
    			hash[s[j]]--;
    			if(hash[s[j]] == 0) difCount--;
    			j++;
    		}
    		ans = max(ans, i-j+1);
        	}
    	return ans;
    }
};

// int main(){
// 	Solution s = Solution();
// 	cout << s.lengthOfLongestSubstringKDistinct("bacc", 2) << endl;
// }

