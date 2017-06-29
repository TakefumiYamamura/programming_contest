#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>


using namespace std;

class StringTransform
{

public:
	string isPossible(string s, string t){
		string ok = "Possible";
		string no =  "Impossible";
		if(s[0] != t[0]) return no;
		map<char, int> hash;
		for (int i = 0; i < s.length(); ++i)
		{
			hash[s[i]]++;
		}

		for (int i = s.length() -1; i > 0; --i)
		{
			hash[s[i]]--;
			if(s[i] == t[i]) continue;
			if(hash.find(t[i]) == hash.end() || hash[s[i]] == 0) return no;
		}
		return ok;
	}
};
