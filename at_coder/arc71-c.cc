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
	vector<map<char, int> > hash_array;
	Solver();

	void exec();
};

Solver::Solver(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		strs.push_back(tmp);
		map<char, int> tmp_hash;
		for (int j = 0; j < tmp.length(); ++j)
		{
			tmp_hash[tmp[j]]++;
		}
		hash_array.push_back(tmp_hash);
	}
}

void Solver::exec(){
	vector<int> char_nums = vector<int>(26, 100);
	for (char c = 'a'; c <= 'z'; ++c)
	{
		for (int i = 0; i < n; ++i)
		{
			char_nums[c-'a'] = min(hash_array[i][c], char_nums[c-'a']);
		}
	}
	string ans = "";
	for (char c = 'a'; c <= 'z'; ++c)
	{
		for (int i = 0; i < char_nums[c-'a']; ++i)
		{
			ans += c;
		}
	}
	cout << ans << endl;
}

int main(){
	Solver solution = Solver();
	solution.exec();
}
