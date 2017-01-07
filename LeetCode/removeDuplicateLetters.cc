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
    string removeDuplicateLetters(string s) {
        map<char, int> hash;
        map<char, bool> visited;
        string ans = "0";
        for (int i = 0; i < s.length(); ++i)
        {
            hash[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            hash[s[i]]--;
            if(visited[s[i]]) continue;
            visited[s[i]] = true;
            while(ans.back() >= s[i] && hash[ans.back()] > 0){
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += s[i];
        }
        return ans.substr(1);

    }
};

// int main(){

// 	Solution s = Solution();
// 	cout << s.removeDuplicateLetters("bcabc") << endl;
// }

