#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

struct Character {
    char cur;
    char before;
};

bool operator<(const Character& a, const Character& b)
{
	if(a.cur == b.cur){
		return a.before < b.before;
	}
	return a.cur < b.cur;
}


class AlphabetOrderDiv2
{
public:
	string isOrdered(vector<string> words){
		map<Character, int> hash1;
		map<Character, int> hash2;
		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = words[i].length()-1; j >= 0; --j)
			{
				for (int k = j-1; k >= 0 ; --k)
				{
					string tmpW = words[i];
					Character tmp = {tmpW[j], tmpW[k]};
					hash1[tmp]++;
				}
			}
		}
		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = 0; j < words[i].length(); ++j)
			{
				for (int k = j+1; k < words[i].length(); ++k)
				{
					string tmpW = words[i];
					Character tmp = {tmpW[j], tmpW[k]};
					hash2[tmp]++;
				}
			}

		}
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				if(i == j) continue;
				Character tmp = {(char)(i+'a'), (char)(j+'a')};
				if(hash1[tmp] > 0 && hash2[tmp] > 0){
					return "Impossible";
				}
			}
		}
		return "Possible";
	}
};
