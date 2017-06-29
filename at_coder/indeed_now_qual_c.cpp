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
	int n, q;
	vector<int> s;
	vector<int> k;
	map<int, int> hash;
	Solver(){
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			s.push_back(tmp);
		}

		cin >> q;
		for (int i = 0; i < q; ++i)
		{
			int tmp;
			cin >> tmp;
			k.push_back(tmp);
		}
	}
	void exec(){

		for (int i = 0; i < n; ++i)
		{
			hash[s[i]]++;
		}
		hash[0]++;

		map<int, int> rev_hash;
		for (auto itr = hash.rbegin(); itr != hash.rend(); ++itr)
		{
			auto itr2 = ++itr;
			itr--;
			if(itr2 == hash.rend()) break;
			hash[itr2->first] = itr2->second + itr->second;
		}

		for (auto itr = hash.begin(); itr != hash.end(); ++itr)
		{
			rev_hash[itr->second] = itr->first;
		}

		for (int i = 0; i < q; ++i)
		{
			auto itr = rev_hash.upper_bound(k[i]);
			if(itr->second == 0){
				cout << 0 << endl;
				continue;
			}
			
			cout << itr->second + 1 << endl; 

		}
	}
};

int main(){
	Solver s = Solver();
	s.exec();
}