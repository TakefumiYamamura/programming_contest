#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#define ll long long
using namespace std;

#define MOD 1000000007

class Solve
{
private:
	string str;
	unordered_map<string, int> hash;
	map<int, vector<string> > rev_hash;

public:
	Solve(){
		cin >> str;
	}

	void exec(){
		for (int i = 1; i < str.length(); ++i)
		{
			string tmp = "";
			tmp += str[i-1];
			tmp += str[i];
			hash[tmp]++;
		}

		for (auto itr1 = hash.begin(); itr1 != hash.end(); ++itr1)
		{
			// cout << itr1->first << "   " << itr1->second << endl;
			rev_hash[itr1->second].push_back(itr1->first);
		}

		auto itr2 = rev_hash.end();
		while(itr2 != rev_hash.begin()){
			itr2--;
			vector<string> tmp_array_string = itr2->second;
			sort(tmp_array_string.begin(), tmp_array_string.end());
			for (int i = 0; i < tmp_array_string.size(); ++i)
			{
				cout << tmp_array_string[i] << endl;
			}			
		}
	}
};

int main(){
	Solve solver = Solve();
	solver.exec();
}
