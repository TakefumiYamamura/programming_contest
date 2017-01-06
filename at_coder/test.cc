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
    	map<char, vector<int> > hash;
    	string ans;
    	vector<int> locate[26];
    	for (int i = 0; i < s.length(); ++i)
    	{
            hash[(char)s[i]].push_back(i);
            // locate[s[i] - 'a'].push_back(i);
    	}
        int bitMask = 0;
        int itr = -1;
        for (int i = 0; i < 26; ++i)
        {
            if(hash[(char)(i + 'a')].size() == 0) continue;
            cout << (char)(i + 'a') << endl;
            vector<int> tmp = hash[(char)(i + 'a')];
            for (int j = 0; j < tmp.size() ; ++j)
            {
                cout << tmp[j] << " " ;
            }
            cout << "saigo "<<  tmp[tmp.size() - 1] <<endl;
        }


        for (int i = 0; i < 26; ++i)
        {
            if(hash[(char)(i + 'a')].size() == 0) continue;
            vector<int> tmp = hash[(char)(i + 'a')];
            // if(locate[i].size() == 0) continue;
            // int loc = tmp[lower_bound(tmp.begin(), tmp.end(), itr) - locate[i].begin()];
            // int loc = lower_bound(locate[i].begin(), locate[i].end(), itr) - locate[i].begin();
            if(tmp[tmp.size() - 1] < itr){
                bitMask |= 1 << tmp[tmp.size() - 1];
            }else{
                // itr = tmp[loc];
                bitMask |= 1 << *lower_bound(tmp.begin(), tmp.end(), itr);
                itr = max(itr, *lower_bound(tmp.begin(), tmp.end(), itr)); 
                // ans.push_back( (char)('a' + *lower_bound(locate[i].begin(), locate[i].end(), itr)) );
            }

            cout << itr << endl;
            for (int j = 0; j < s.length(); ++j)
            {
                if(1 << j & bitMask){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
            cout << endl;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if(1 << i & bitMask) ans.push_back(s[i]);
        }
    	return ans;
    }
};

int main(){
    // vector<int> test;
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(5);
    // cout << *lower_bound(test.begin(), test.end(), 6)<< endl;
    // cout << upper_bound(test.begin(), test.end(), 1) - test.begin() << endl;
	Solution s = Solution();
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
}

