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

class MakePalindrome
{
public:
	 vector <string> constructMinimal(string card){
		vector<string> ans;
		map<char, int> hash;
		for (int i = 0; i < card.length(); ++i)
		{
			hash[card[i]]++;
		}
		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			string tmp = "";
			if(itr->second % 2 == 1){
				for (int i = 0; i < itr->second; ++i)
				{
					tmp = tmp + itr->first;
				}
				ans.push_back(tmp);
			}
		}

		string last;
		if(ans.size() == 0){
			last = "";
		}else{
			last = ans[0];
		}

		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			if(itr->second % 2 == 0){
				for (int i = 0; i < itr->second / 2; ++i)
				{
					last = itr->first + last + itr->first;
				}
			}
		}
		if(ans.size() == 0){
			ans.push_back(last);
		}else{
			ans[0] = last;
		}
		return ans;
	}
};
