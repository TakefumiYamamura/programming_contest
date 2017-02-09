#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class PalindromicSubseq2
{
public:
	 int solve(string s){
	 	unordered_map<char, int> hash;
	 	for (int i = 0; i < s.length(); ++i)
	 	{
	 		if(hash.end() == hash.find(s[i])){
	 			hash[s[i]] = 0;
	 		}
	 		hash[s[i]]++;
	 	}
		vector<int> tmp;
		tmp.resize(s.length());
		for (int i = 0; i < s.length(); ++i)
		{
			tmp[i] = 0;
		}
		unordered_map<char, int> l_hash;
		for (int i = 0; i < s.length(); ++i)
		{
	 		if(l_hash.end() == l_hash.find(s[i])){
	 			l_hash[s[i]] = 0;
	 		}
			l_hash[s[i]]++;
			for (auto itr = hash.begin(); itr != hash.end(); ++itr)
			{
				if(l_hash[itr->first] > 0) tmp[i]++;
			}
			hash[s[i]]--;
		}
		int ans = 0;

		for (int i = 0; i < s.length(); ++i)
		{
			ans ^= i * tmp[i];
		}
		return ans;
	}
};
