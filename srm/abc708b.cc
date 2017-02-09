#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class BuildingStrings
{
public:
	vector<string> findAny(int K){
		vector<string> ans;
		int count = K / 26;
		string maxS = "abccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
		while(count >= 50){
			ans.push_back(maxS);
			count -= 50;
		}
		string tmpS = "abcdefghijklmnopqrstuvwxyz";
		if(count == 0){

		}else if(count >= 26){
			int tmpC = count - 26;
			while(tmpC > 0){
				tmpS += "a";
				tmpC--;
			}
			ans.push_back(tmpS);
		}else{
			int tmpC = 26 - count;
			while(tmpC > 0){
				tmpS[26 - tmpC] = 'a';
				tmpC--;
			}
			ans.push_back(tmpS);
		}
		int res = K % 26;
		string addS = "";
		if(res > 0){
			while(res > 0){
				addS += "a";
				res--;
			}
			ans.push_back(addS);
		}
		return ans;
	}
};
