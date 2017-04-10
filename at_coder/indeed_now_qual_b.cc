#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long

class Solver
{
public:
	int n;
	vector<string> strs;
	Solver(){
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string tmp_str;
			cin >> tmp_str;
			strs.push_back(tmp_str);
		}
	}
	string judege(string str){
		string indeed = "indeednow";
		if(str.length() != indeed.length()){
			return "NO";
		}
		map<char, int> hash;
		for (int i = 0; i < indeed.length(); ++i)
		{
			hash[indeed[i]]++;
		}
		map<char, int> hash2;
		for (int i = 0; i < str.length(); ++i)
		{
			hash2[str[i]]++;
		}

		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			if(hash2[itr->first] != itr->second) return "NO";
		}
		return "YES";
	}
	void exec(){
		for (int i = 0; i < n; ++i)
		{
			cout << judege(strs[i]) << endl;
		}
	}
};

int main(){
	Solver s = Solver();
	s.exec();
}